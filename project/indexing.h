#ifndef _INDEXING_H
#define _INDEXING_H

#include "inverted_index.h"

void indexing();
void hash_parse_insert(char *flie_name);
char *str_tolower(char *str);
void hash_insert(char *word, char *file_name);
void data_insert(RecordNode *pos, char *file_name);

#endif
