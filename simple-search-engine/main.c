#include <stdio.h>
#include "indexing.h"
#include "searching.h"

int main(int argc, char **argv)
{
    char *word;
    if (argc != 2)
    {
        printf("Please enter a word to search for.");
        return -1;
    }
    word = argv[1];
    indexing();
    searching(word);
    return 0;
}
