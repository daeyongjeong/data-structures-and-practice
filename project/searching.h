#ifndef _SEARCHING_H
#define _SEARCHING_H

#include "inverted_index.h"

void hash_print();
void data_print(RecordNode *pos);

void searching(char *word);
void data_sort(RecordNode *pos);
void swap(DataNode *a, DataNode *b);
void data_search(RecordNode *pos);
void file_search(char *word, char *file_name, int word_count);

#endif
