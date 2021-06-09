#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "indexing.h"
#include "inverted_index.h"
#include "str_tolower.h"

static int found_docs = 0;
static int indexed_words = 0;
static int comparisons = 0;

void indexing()
{
    char filename[FILENAME_LENGTH];

    printf("INDEXING...\n\n");
    for (int i = 0; i < 100; i++)
    {
        sprintf(filename, "doc%03d.txt", i + 1);
        parse_file(filename);
    }
    printf("Total number of documents found: %d\n", found_docs);
    printf("Total number of indexed words: %d\n", indexed_words);
    printf("Total number of comparisons: %d\n\n", comparisons);
}

void parse_file(const char *filename)
{
    const char *DELIM = "\a\b\t\n\v\f\r !\"#$%%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~";

    FILE *fp;
    char buf[255];
    char *token;
    char *last;
    int offset = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
        return;

    while (fgets(buf, 255, fp))
    {
        token = strtok_r(buf, DELIM, &last);
        while (token != NULL)
        {
            str_tolower(token);
            insert_record(token, offset, filename);
            offset++;
            token = strtok_r(NULL, DELIM, &last);
        }
    }

    fclose(fp);
    found_docs++;
}

void insert_record(char *word, const int offset, const char *filename)
{
    int index = hash(word) % TABLE_SIZE;
    RecordNode *p = inverted_index[index];
    RecordNode *prev = NULL;
    RecordNode *new_node;

    while (p != NULL)
    {
        comparisons++;
        if (strcmp(p->word, word) == 0)
        {
            insert_data(p, offset, filename);
            return;
        }
        prev = p;
        p = p->next;
    }

    new_node = (RecordNode *)malloc(sizeof(RecordNode));
    new_node->word = (char *)malloc(sizeof(char) * strlen(word));
    strcpy(new_node->word, word);
    new_node->refhead = NULL;
    new_node->next = NULL;
    insert_data(new_node, offset, filename);

    if (prev)
        prev->next = new_node;
    else
        inverted_index[index] = new_node;

    indexed_words++;
}

void insert_data(RecordNode *parent, const int offset, const char *filename)
{
    RefNode *p = parent->refhead;
    RefNode *prev = NULL;
    RefNode *new_node;

    while (p != NULL)
    {
        comparisons++;
        if (strcmp(p->filename, filename) == 0)
        {
            p->word_count++;
            return;
        }
        prev = p;
        p = p->next;
    }

    new_node = (RefNode *)malloc(sizeof(RefNode));
    strcpy(new_node->filename, filename);
    new_node->word_count = 1;
    new_node->next = NULL;

    if (prev)
        prev->next = new_node;
    else
        parent->refhead = new_node;
}
