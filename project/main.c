#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main()
{
    hash_index();
    hash_search("computer");
    //hash_print();
    return 0;
}

void hash_index()
{
    char file_name[WORD_SIZE];
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
    HashNode *cur, *prev = NULL;

    for (cur = hash_table[key]; cur; prev = cur, cur = cur->next)
    {
        number_of_comparisons++;
        if (strcmp(cur->word, word) == 0)
        {
            data_insert(cur, file_name);
            return;
        }
    }

    HashNode *new_node = (HashNode *)malloc(sizeof(HashNode));
    strcpy(new_node->word, word);
    new_node->data = NULL;
    new_node->next = NULL;
    data_insert(new_node, file_name);
    if (prev)
        prev->next = new_node;
    else
        hash_table[key] = new_node;
    number_of_indexed_words++;
}

void data_insert(HashNode *pos, char *file_name)
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

void hash_print()
{
    HashNode *cur;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cur = hash_table[i];
        while (cur)
        {
            printf("\nword: %s\n", cur->word);
            data_print(cur);
            cur = cur->next;
        }
    }
}

void data_print(HashNode *pos)
{
    DataNode *cur = pos->data;
    while (cur)
    {
        printf("- document: %s, count: %d\n", cur->file_name, cur->word_count);
        cur = cur->next;
    }
}

unsigned long hash(unsigned char *str) // djb2
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % 10000;
}

void hash_search(char *word)
{
    int key = hash(word);
    HashNode *cur;

    for (cur = hash_table[key]; cur; cur = cur->next)
    {
        search_comparisons++;
        if (strcmp(cur->word, word) == 0)
        {
            printf("hello!!!\n");
            data_sort(cur);
            data_search(cur);
            return;
        }
    }
}

void data_sort(HashNode *pos)
{
    DataNode *cur = pos->data, *temp;
    while (cur != NULL)
    {
        temp = cur;
        while (temp->next != NULL) //travel till the second last element
        {
            if (temp->word_count < temp->next->word_count) // compare the data of the nodes
                swap(temp, temp->next);

            temp = temp->next; // move to the next element
        }
        cur = cur->next; // move to the next node
    }
}

void swap(DataNode *a, DataNode *b)
{
    char temp_file_name[WORD_SIZE];
    int temp_word_count;
    strcpy(temp_file_name, a->file_name);
    strcpy(a->file_name, b->file_name);
    strcpy(b->file_name, temp_file_name);
    temp_word_count = a->word_count;
    a->word_count = b->word_count;
    b->word_count = temp_word_count;
}

void data_search(HashNode *pos)
{
    DataNode *cur;

    for (cur = pos->data; cur; cur = cur->next)
    {
        search_comparisons++;
        printf("%s (%s: %d)\n", cur->file_name, pos->word, cur->word_count);
        file_search(pos->word, cur->file_name, cur->word_count);
    }
}

void file_search(char *word, char *file_name, int word_count)
{
    printf("...\n");
}
