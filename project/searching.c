#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "searching.h"

static int search_comparisons = 0;

void hash_print()
{
    RecordNode *cur;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cur = inverted_index[i];
        while (cur)
        {
            printf("\nword: %s\n", cur->word);
            data_print(cur);
            cur = cur->next;
        }
    }
}

void data_print(RecordNode *pos)
{
    DataNode *cur = pos->data;
    while (cur)
    {
        printf("- document: %s, count: %d\n", cur->file_name, cur->word_count);
        cur = cur->next;
    }
}

void searching(char *word)
{
    int key = hash(word);
    RecordNode *cur;

    for (cur = inverted_index[key]; cur; cur = cur->next)
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

void data_sort(RecordNode *pos)
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
    char temp_file_name[FILE_NAME_LENGTH];
    int temp_word_count;
    strcpy(temp_file_name, a->file_name);
    strcpy(a->file_name, b->file_name);
    strcpy(b->file_name, temp_file_name);
    temp_word_count = a->word_count;
    a->word_count = b->word_count;
    b->word_count = temp_word_count;
}

void data_search(RecordNode *pos)
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
