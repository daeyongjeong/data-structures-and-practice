#ifndef _SEARCHING_H
#define _SEARCHING_H

#include "inverted_index.h"

void hash_print();
void data_print(RecordNode *pos);

void searching(char *word);
void search_record(char *word);
void sort_data(RecordNode *pos);
void reverse_data(RecordNode *pos);
void swap_data(DataNode *a, DataNode *b);
void search_data(RecordNode *pos);
void search_file(char *word, DataNode *data);
int str_match(char *str1, char *str2);

#endif
