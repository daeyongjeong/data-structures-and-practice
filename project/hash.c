#include "hash.h"

unsigned long hash(unsigned char *str) // djb2
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % 10000;
}
