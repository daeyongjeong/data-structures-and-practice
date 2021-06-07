#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "searching.h"
#include "str_tolower.h"

static int comparisons = 0;

void searching(char *word)
{
    search_record(word);
    printf("Total number of comparison: %d\n", comparisons);
}

void search_record(char *word)
{
    int key = hash(word);

    for (RecordNode *cur = inverted_index[key]; cur; cur = cur->next)
    {
        comparisons++;
        if (strcmp(cur->word, word) == 0)
        {
            sort_ref(cur);
            search_reflist(cur);
            return;
        }
    }
}

void sort_ref(RecordNode *pos)
{
    RefNode *pi = pos->reflist;
    RefNode *pj, *temp;

    while (pi != NULL)
    {
        pj = pi;
        while (pj->next != NULL)
        {
            comparisons++;
            if (pj->word_count > pj->next->word_count)
                swap_refnode(pj, pj->next);
            pj = pj->next;
        }
        pi = pi->next;
    }
    reverse_reflist(pos);
}

void reverse_reflist(RecordNode *pos)
{
    RefNode *prev = NULL;
    RefNode *cur = pos->reflist;
    RefNode *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    pos->reflist = prev;
}

void swap_refnode(RefNode *a, RefNode *b)
{
    char temp_file_name[FILENAME_LENGTH];
    int temp_word_count;
    strcpy(temp_file_name, a->filename);
    strcpy(a->filename, b->filename);
    strcpy(b->filename, temp_file_name);
    temp_word_count = a->word_count;
    a->word_count = b->word_count;
    b->word_count = temp_word_count;
}

void search_reflist(RecordNode *pos)
{
    RefNode *cur;

    for (cur = pos->reflist; cur; cur = cur->next)
    {
        printf("%s (%s: %d)\n", cur->filename, pos->word, cur->word_count);
        search_file(pos->word, cur);
    }
}

void search_file(char *word, RefNode *data)
{
    FILE *fp = fopen(data->filename, "r");
    if (fp == NULL)
        return;

    const char *DELIMITER = "\t\v\f\r\n ";
    char line[255];
    char recent_block[13][WORD_LENGTH];
    char *token, *last;
    int offset = 0;
    int found = 0;
    int target;

    while (fgets(line, 255, fp) && found < data->word_count)
    {
        token = strtok_r(line, DELIMITER, &last);
        while (token != NULL)
        {
            strcpy(recent_block[offset % 13], token);
            target = offset - 3;
            if (offset >= 3 && str_match(recent_block[(target + 13) % 13], word))
            {
                found++;
                if (target > 3)
                    printf("... ");
                for (int j = -3; j <= 3; j++)
                    if (target + j >= 0 && target + j <= offset)
                        printf("%s ", recent_block[(target + j + 13) % 13]);
                printf("...\n");
            }
            offset++;
            token = strtok_r(NULL, DELIMITER, &last);
        }
    }

    for (int i = 3; i > 0; i--)
    {
        target = offset - i;
        if (target >= 0 && str_match(recent_block[(target + 13) % 13], word))
        {
            found++;
            if (target > 3)
                printf("... ");
            for (int j = -3; j <= 3; j++)
                if (target + j >= 0 && target + j < offset)
                    printf("%s ", recent_block[(target + j + 13) % 13]);
            printf("\n");
        }
    }

    printf("\n");
    fclose(fp);
}

int str_match(char *str1, char *str2)
{
    const char *DELIMITER = "\a\b\t\n\v\f\r !\"#$%%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~";
    char temp[255];
    char *token, *last;

    strcpy(temp, str1);
    str_tolower(temp);
    token = strtok_r(temp, DELIMITER, &last);

    while (token != NULL)
    {
        comparisons++;
        if (strcmp(token, str2) == 0)
        {
            free(temp);
            return 1;
        }
        token = strtok_r(NULL, DELIMITER, &last);
    }
    free(temp);
    return 0;
}
