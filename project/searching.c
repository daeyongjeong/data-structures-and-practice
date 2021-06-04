#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "searching.h"

static int number_of_comparisons = 0;

void searching(char *word)
{
    search_record(word);
    printf("Total number of comparison: %d\n", number_of_comparisons);
}

void search_record(char *word)
{
    int key = hash(word);
    RecordNode *cur;

    for (cur = inverted_index[key]; cur; cur = cur->next)
    {
        number_of_comparisons++;
        if (strcmp(cur->word, word) == 0)
        {
            sort_data(cur);
            search_data(cur);
            return;
        }
    }
}

void sort_data(RecordNode *pos)
{
    DataNode *cur = pos->data, *temp;
    while (cur != NULL)
    {
        temp = cur;
        while (temp->next != NULL) //travel till the second last element
        {
            number_of_comparisons++;
            if (temp->word_count < temp->next->word_count) // compare the data of the nodes
                swap_data(temp, temp->next);

            temp = temp->next; // move to the next element
        }
        cur = cur->next; // move to the next node
    }
}

void swap_data(DataNode *a, DataNode *b)
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

void search_data(RecordNode *pos)
{
    DataNode *cur;

    for (cur = pos->data; cur; cur = cur->next)
    {
        printf("%s (%s: %d)\n", cur->file_name, pos->word, cur->word_count);
        search_file(pos->word, cur);
    }
}

void search_file(char *word, DataNode *data)
{
    FILE *fp = fopen(data->file_name, "r");
    if (fp == NULL)
        return;

    const char *DELIMITER = "\t\v\f\r\n ";
    char line[255];
    char word_around_token[13][WORD_LENGTH];
    char *token, *last;
    int offset = 0;
    int found = 0;

    while (fgets(line, 255, fp) && found < data->word_count)
    {
        token = strtok_r(line, DELIMITER, &last);
        while (token != NULL)
        {
            strcpy(word_around_token[offset % 13], token);

            if (offset >= 3 && str_match(word_around_token[(offset - 3 + 13) % 13], word))
            {
                found++;
                if (offset >= 7)
                    printf("... ");
                for (int i = 6; i > 3; i--)
                    if (offset >= i)
                        printf("%s ", word_around_token[(offset - i + 13) % 13]);
                for (int i = 3; i >= 0; i--)
                    printf("%s ", word_around_token[(offset - i + 13) % 13]);
                printf("...\n");
            }
            offset++;
            token = strtok_r(NULL, DELIMITER, &last);
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
    token = strtok_r(temp, DELIMITER, &last);

    while (token != NULL)
    {
        number_of_comparisons++;
        if (strcmp(token, str2) == 0)
            return 1;
        token = strtok_r(NULL, DELIMITER, &last);
    }
    return 0;
}
