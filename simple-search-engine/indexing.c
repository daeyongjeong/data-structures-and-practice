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
    printf("Total number of documents: %d\n", found_docs);
    printf("Total number of indexed words: %d\n", indexed_words);
    printf("Total number of comparisons: %d\n\n", comparisons);
}

void parse_file(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return;

    const char *DELIMITER = "\a\b\t\n\v\f\r !\"#$%%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~";
    char line[255];
    char *token;
    int offset = 0;

    while (fgets(line, 255, fp))
    {
        token = strtok(line, DELIMITER);
        while (token != NULL)
        {
            str_tolower(token);
            insert_record(token, offset, filename);
            offset++;
            token = strtok(NULL, DELIMITER);
        }
    }
    fclose(fp);
    found_docs++;
}

void insert_record(char *word, int offset, char *filename)
{
    int key = hash(word);
    RecordNode *cur, *prev = NULL;

    for (cur = inverted_index[key]; cur; prev = cur, cur = cur->next)
    {
        comparisons++;
        if (strcmp(cur->word, word) == 0)
        {
            insert_data(cur, offset, filename);
            return;
        }
    }

    RecordNode *new_node = (RecordNode *)malloc(sizeof(RecordNode));
    strcpy(new_node->word, word);
    new_node->reflist = NULL;
    new_node->next = NULL;
    insert_data(new_node, offset, filename);
    if (prev)
        prev->next = new_node;
    else
        inverted_index[key] = new_node;
    indexed_words++;
}

void insert_data(RecordNode *pos, int offset, char *filename)
{
    RefNode *cur, *prev = NULL;

    for (cur = pos->reflist; cur; prev = cur, cur = cur->next)
    {
        comparisons++;
        if (strcmp(cur->filename, filename) == 0)
        {
            cur->word_count++;
            return;
        }
    }

    RefNode *new_node = (RefNode *)malloc(sizeof(RefNode));
    strcpy(new_node->filename, filename);
    new_node->word_count = 1;
    new_node->next = NULL;
    if (prev)
        prev->next = new_node;
    else
        pos->reflist = new_node;
}
