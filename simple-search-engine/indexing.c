#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "indexing.h"
#include "inverted_index.h"
#include "str_tolower.h"

static int number_of_documents = 0;
static int number_of_indexed_words = 0;
static int number_of_comparisons = 0;

void indexing()
{
    char file_name[FILE_NAME_LENGTH];

    printf("INDEXING...\n\n");
    for (int i = 0; i < 100; i++)
    {
        sprintf(file_name, "doc%03d.txt", i + 1);
        parse_file(file_name);
    }
    printf("Total number of documents: %d\n", number_of_documents);
    printf("Total number of indexed words: %d\n", number_of_indexed_words);
    printf("Total number of comparisons: %d\n\n", number_of_comparisons);
}

void parse_file(char *file_name)
{
    FILE *fp = fopen(file_name, "r");
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
            insert_record(token, offset, file_name);
            offset++;
            token = strtok(NULL, DELIMITER);
        }
    }
    fclose(fp);
    number_of_documents++;
}

void insert_record(char *word, int offset, char *file_name)
{
    int key = hash(word);
    RecordNode *cur, *prev = NULL;

    for (cur = inverted_index[key]; cur; prev = cur, cur = cur->next)
    {
        number_of_comparisons++;
        if (strcmp(cur->word, word) == 0)
        {
            insert_data(cur, offset, file_name);
            return;
        }
    }

    RecordNode *new_node = (RecordNode *)malloc(sizeof(RecordNode));
    strcpy(new_node->word, word);
    new_node->data = NULL;
    new_node->next = NULL;
    insert_data(new_node, offset, file_name);
    if (prev)
        prev->next = new_node;
    else
        inverted_index[key] = new_node;
    number_of_indexed_words++;
}

void insert_data(RecordNode *pos, int offset, char *file_name)
{
    DataNode *cur, *prev = NULL;

    for (cur = pos->data; cur; prev = cur, cur = cur->next)
    {
        number_of_comparisons++;
        if (strcmp(cur->file_name, file_name) == 0)
        {
            cur->word_count++;
            return;
        }
    }

    DataNode *new_node = (DataNode *)malloc(sizeof(DataNode));
    strcpy(new_node->file_name, file_name);
    new_node->word_count = 1;
    new_node->next = NULL;
    if (prev)
        prev->next = new_node;
    else
        pos->data = new_node;
}
