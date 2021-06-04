#ifndef _INVERTED_INDEX_H
#define _INVERTED_INDEX_H

#define TABLE_SIZE 10000
#define WORD_LENGTH 100
#define FILE_NAME_LENGTH 255

typedef struct data_node
{
    char file_name[FILE_NAME_LENGTH];
    int word_count;
    struct data_node *next;
} DataNode;

typedef struct record_node
{
    char word[WORD_LENGTH];
    DataNode *data;
    struct record_node *next;
} RecordNode;

RecordNode *inverted_index[TABLE_SIZE];

#endif
