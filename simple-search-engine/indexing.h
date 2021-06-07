#ifndef _INDEXING_H
#define _INDEXING_H

#include "inverted_index.h"

void indexing();
void parse_file(char *flie_name);
char *str_tolower(char *str);
void insert_record(char *word, int offset, char *filename);
void insert_data(RecordNode *pos, int offset, char *filename);

#endif
