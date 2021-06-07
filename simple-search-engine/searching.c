#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "searching.h"
#include "str_tolower.h"

static int comparisons = 0;

void searching(const char *word)
{
    search_record(word);
    printf("Total number of comparison: %d\n", comparisons);
}

void search_record(const char *word)
{
    int key = hash(word);
    RecordNode *p = inverted_index[key];

    while (p != NULL)
    {
        comparisons++;
        if (strcmp(p->word, word) == 0)
        {
            sort_ref(p);
            search_reflist(p);
            return;
        }
        p = p->next;
    }
}

void sort_ref(const RecordNode *parent)
{
    RefNode *pi = parent->refhead;
    RefNode *pj;

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
    reverse_reflist(parent);
}

void reverse_reflist(RecordNode *parent)
{
    RefNode *p = parent->refhead;
    RefNode *prev = NULL;
    RefNode *next = NULL;

    while (p != NULL)
    {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    parent->refhead = prev;
}

void swap_refnode(RefNode *a, RefNode *b)
{
    char temp_filename[FILENAME_LENGTH];
    int temp_word_count;
    strcpy(temp_filename, a->filename);
    strcpy(a->filename, b->filename);
    strcpy(b->filename, temp_filename);
    temp_word_count = a->word_count;
    a->word_count = b->word_count;
    b->word_count = temp_word_count;
}

void search_reflist(const RecordNode *parent)
{
    RefNode *p = parent->refhead;

    while (p != NULL)
    {
        printf("%s (%s: %d)\n", p->filename, parent->word, p->word_count);
        search_file(parent->word, p);
        p = p->next;
    }
}

void search_file(const char *word, const RefNode *data)
{
    const char *DELIM = "\t\v\f\r\n ";
    const int MASK = 7;

    FILE *fp;
    char buf[255];
    int found = 0;
    char *token;
    char **last;
    char recent_block[MASK][WORD_LENGTH];
    int offset = 0;
    int target;

    if (fp = fopen(data->filename, "r") == NULL)
        return;

    while (fgets(buf, 255, fp) && found < data->word_count)
    {
        token = strtok_r(buf, DELIM, last);
        while (token != NULL)
        {
            strcpy(recent_block[offset % MASK], token);
            target = offset - 3;
            if (target >= 0 && block_word_match(recent_block[target % MASK], word))
            {
                found++;
                if (target > 3)
                    printf("... ");
                for (int j = -3; j <= 3; j++)
                    if (target + j >= 0 && target + j <= offset)
                        printf("%s ", recent_block[(target + j + MASK) % MASK]);
                printf("...\n");
            }
            offset++;
            token = strtok_r(NULL, DELIM, last);
        }
    }

    for (int i = 3; i > 0; i--)
    {
        target = offset - i;
        if (target >= 0 && block_word_match(recent_block[target % MASK], word))
        {
            found++;
            if (target > 3)
                printf("... ");
            for (int j = -3; j <= 3; j++)
                if (target + j >= 0 && target + j < offset)
                    printf("%s ", recent_block[(target + j + MASK) % MASK]);
            printf("\n");
        }
    }

    printf("\n");
    fclose(fp);
}

int block_word_match(const char *block, const char *word)
{
    const char *DELIM = "\a\b\t\n\v\f\r !\"#$%%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~";

    char *token;
    char **last;
    char temp[255];

    strcpy(temp, block);
    str_tolower(temp);
    token = strtok_r(temp, DELIM, last);

    while (token != NULL)
    {
        comparisons++;
        if (strcmp(token, word) == 0)
            return 1;
        token = strtok_r(NULL, DELIM, last);
    }
    return 0;
}
