#ifndef _SEARCHING_H
#define _SEARCHING_H

#include "inverted_index.h"

void searching(char *word);
void search_record(char *word);
void sort_reflist(RecordNode *pos);
void reverse_reflist(RecordNode *pos);
void swap_refnode(RefNode *a, RefNode *b);
void search_reflist(RecordNode *pos);
void search_file(char *word, RefNode *data);
int str_match(char *str1, char *str2);

#endif
