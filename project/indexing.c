#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "indexing.h"
#include "inverted_index.h"

static int number_of_documents = 0;
static int number_of_indexed_words = 0;
static int number_of_comparisons = 0;

void indexing()
{
    char file_name[FILE_NAME_LENGTH];
    for (int i = 0; i < 4; i++)
    {
        sprintf(file_name, "doc%03d.txt", i + 1);
        hash_parse_insert(file_name);
    }
    printf("Total number of documents: %d\n", number_of_documents);
    printf("Total number of indexed words: %d\n", number_of_indexed_words);
    printf("Total number of comparisons: %d\n\n", number_of_comparisons);
}

void hash_parse_insert(char *file_name)
{
    FILE *fp = fopen(file_name, "r");
    const char *DELIMITER = "\a\b\t\n\v\f\r !\"#$%%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~";

    if (fp == NULL)
        return;
    char line[255];
    char *token;

    while (fgets(line, 255, fp))
    {
        token = strtok(line, DELIMITER);
        while (token != NULL)
        {
            str_tolower(token);
            hash_insert(token, file_name);
            token = strtok(NULL, DELIMITER);
        }
    }
    fclose(fp);
    number_of_documents++;
}

char *str_tolower(char *str)
{
    for (char *p = str; *p; p++)
        *p = tolower(*p);
    return str;
}

void hash_insert(char *word, char *file_name)
{
    int key = hash(word);
    RecordNode *cur, *prev = NULL;

    for (cur = inverted_index[key]; cur; prev = cur, cur = cur->next)
    {
        number_of_comparisons++;
        if (strcmp(cur->word, word) == 0)
        {
            data_insert(cur, file_name);
            return;
        }
    }

    RecordNode *new_node = (RecordNode *)malloc(sizeof(RecordNode));
    strcpy(new_node->word, word);
    new_node->data = NULL;
    new_node->next = NULL;
    data_insert(new_node, file_name);
    if (prev)
        prev->next = new_node;
    else
        inverted_index[key] = new_node;
    number_of_indexed_words++;
}

void data_insert(RecordNode *pos, char *file_name)
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
