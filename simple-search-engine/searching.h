#ifndef _SEARCHING_H
#define _SEARCHING_H

#include "inverted_index.h"

void searching(const char *word);
void search_record(const char *word);
void sort_reflist(RecordNode *pos);
void reverse_reflist(RecordNode *parent);
void swap_refnode(RefNode *a, RefNode *b);
void search_reflist(const RecordNode *parent);
void search_file(const char *word, const RefNode *data);
int block_word_match(const char *block, const char *word);

#endif
