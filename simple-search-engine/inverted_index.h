#ifndef _INVERTED_INDEX_H
#define _INVERTED_INDEX_H

#define TABLE_SIZE 9973
#define WORD_LENGTH 100
#define FILENAME_LENGTH 255

typedef struct ref_node
{
    char filename[FILENAME_LENGTH];
    int word_count;
    struct ref_node *next;
} RefNode;

typedef struct record_node
{
    char *word;
    RefNode *refhead;
    struct record_node *next;
} RecordNode;

RecordNode *inverted_index[TABLE_SIZE];

#endif
