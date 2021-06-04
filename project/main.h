#define TABLE_SIZE 10000
#define WORD_SIZE 100

typedef struct data_node
{
    char file_name[WORD_SIZE];
    int word_count;
    struct data_node *next;
} DataNode;

typedef struct hash_node
{
    char word[WORD_SIZE];
    DataNode *data;
    struct hash_node *next;
} HashNode;

HashNode *hash_table[TABLE_SIZE];

int number_of_documents = 0;
int number_of_indexed_words = 0;
int number_of_comparisons = 0;
int search_comparisons = 0;

void hash_index();
void hash_parse_insert(char *flie_name);
char *str_tolower(char *str);
void hash_insert(char *word, char *file_name);
void data_insert(HashNode *pos, char *file_name);
void hash_print();
void data_print(HashNode *pos);
unsigned long hash(unsigned char *str); // djb2
void hash_search(char *word);
void data_sort(HashNode *pos);
void swap(DataNode *a, DataNode *b);
void data_search(HashNode *pos);
void file_search(char *word, char *file_name, int word_count);
