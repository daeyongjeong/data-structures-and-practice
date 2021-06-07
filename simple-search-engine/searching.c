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
    int index = hash(word) % TABLE_SIZE;
    RecordNode *p = inverted_index[index];

    while (p != NULL)
    {
        comparisons++;
        if (strcmp(p->word, word) == 0)
        {
            bubble_sort(p, length(p));
            reverse_reflist(p);
            search_reflist(p);
            return;
        }
        p = p->next;
    }
}

int length(RecordNode *parent)
{
    RefNode *p = parent->refhead;
    int count = 0;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

/* Function to sort the list */
int bubble_sort(RecordNode *parent, int count)
{
    RefNode **h;
    int i, j, swapped;

    for (i = 0; i <= count; i++)
    {
        h = &parent->refhead;
        swapped = 0;
        for (j = 0; j < count - i - 1; j++)
        {
            RefNode *p1 = *h;
            RefNode *p2 = p1->next;
            if (p1->word_count > p2->word_count)
            {
                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }
            h = &(*h)->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}

/* Function to swap the nodes */
RefNode *swap(RefNode *ptr1, RefNode *ptr2)
{
    RefNode *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
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
    char *last;
    char recent_block[7][WORD_LENGTH];
    int offset = 0;
    int target;

    fp = fopen(data->filename, "r");
    if (fp == NULL)
        return;

    while (fgets(buf, 255, fp) && found < data->word_count)
    {
        token = strtok_r(buf, DELIM, &last);
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
                        printf("%s ", recent_block[(target + j) % MASK]);
                printf("...\n");
            }
            offset++;
            token = strtok_r(NULL, DELIM, &last);
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
                    printf("%s ", recent_block[(target + j) % MASK]);
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
    char *last;
    char temp[255];

    strcpy(temp, block);
    str_tolower(temp);
    token = strtok_r(temp, DELIM, &last);

    while (token != NULL)
    {
        comparisons++;
        if (strcmp(token, word) == 0)
            return 1;
        token = strtok_r(NULL, DELIM, &last);
    }
    return 0;
}
