#ifndef _HASHING_SIMULATION_H
#define _HASHING_SIMULATION_H
#define TABLE_SIZE 1001

typedef struct element
{
    int key;
    int value;
} Element;

void simulation(double loading_density);
void clear_hash_table();
Element get_random_element();
int get_random_key();
void linear_probing_insert(Element item);
void linear_probing_search(Element item);
int hash(int key);

#endif
