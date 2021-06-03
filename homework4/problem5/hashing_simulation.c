#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashing_simulation.h"

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    simulation(0.5);
    simulation(0.8);
    return 0;
}

void simulation(double loading_density)
{
    int i;
    int number_of_samples = (int)(TABLE_SIZE * loading_density);

    clear_hash_table();
    hash_table_size = 0;
    number_of_comparisons = 0;

    // insert random elements until loading density is reached
    while (hash_table_size < number_of_samples)
    {
        Element e = get_random_element();
        linear_probing_insert(e);
    }

    // search for elements in hash table to test successful search cases
    for (i = 0; i < TABLE_SIZE; i++)
        if (hash_table[i].key != -1)
            linear_probing_search(hash_table[i]);

    printf("Number of samples: %d\n", number_of_samples);
    printf("Total number of comparisons: %d\n", number_of_comparisons);
    printf("Average number of comparisons: %f\n", (double)number_of_comparisons / number_of_samples);
}

void clear_hash_table()
{
    int i;
    Element initial = {-1, 0};
    for (i = 0; i < TABLE_SIZE; i++)
        hash_table[i] = initial;
}

Element get_random_element()
{
    int key = get_random_key();
    int value = key + 10000;
    Element e = {key, value};
    return e;
}

int get_random_key()
{
    return rand() % 10000;
}

void linear_probing_insert(Element item)
{
    int i, hash_value;
    i = hash_value = hash(item.key);

    while (hash_table[i].key != -1)
    {
        // duplication
        if (hash_table[i].key == item.key)
            return;

        i = (i + 1) % TABLE_SIZE;

        // table full
        if (i == hash_value)
            return;
    }

    // success
    hash_table[i] = item;
    hash_table_size++;
}

void linear_probing_search(Element item)
{
    int i, hash_value;
    i = hash_value = hash(item.key);

    while (hash_table[i].key != -1)
    {
        number_of_comparisons++;

        // success
        if (hash_table[i].key == item.key)
            return;

        i = (i + 1) % TABLE_SIZE;

        // table full
        if (i == hash_value)
            return;
    }
}

int hash(int key)
{
    return key % TABLE_SIZE;
}
