#ifndef _INDEXING_H
#define _INDEXING_H

#include "inverted_index.h"

void indexing();
void parse_file(const char *flie_name);
void insert_record(const char *word, const int offset, const char *filename);
void insert_data(RecordNode *parent, const int offset, const char *filename);

#endif
