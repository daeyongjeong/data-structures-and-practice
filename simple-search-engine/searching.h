#ifndef _SEARCHING_H
#define _SEARCHING_H

#include "inverted_index.h"

void searching(char *word);
void search_record(char *word);
int length(RecordNode *parent);
int bubble_sort(RecordNode *parent, int count);
RefNode *swap(RefNode *ptr1, RefNode *ptr2);
void reverse_reflist(RecordNode *parent);
void search_reflist(const RecordNode *parent);
void search_file(const char *word, const RefNode *data);
int block_word_match(const char *block, const char *word);

#endif
