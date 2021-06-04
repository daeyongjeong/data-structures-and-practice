#define true 1
#define false 0

typedef struct trie
{
    int isEnd;
    struct trie *data[26];
} Trie;

int build_trie(Trie *head, char *fname);
void trie_insert(Trie *head, char *str);
int trie_search(Trie *head, char *str);
Trie *get_trie_node();
void print_trie(Trie *head, char *str, int level);
