#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashing_simulation.h"

static Element hash_table[TABLE_SIZE];
static int loaded;
static int comparisons;

void simulation(double loading_density)
{
    int number_of_samples = (int)(TABLE_SIZE * loading_density);

    srand(time(NULL));
    clear_hash_table();
    loaded = 0;
    comparisons = 0;

    // insert random elements until loading density is reached
    while (loaded < number_of_samples)
    {
        Element e = get_random_element();
        linear_probing_insert(e);
    }

    // search for elements in hash table to test successful search cases
    for (int i = 0; i < TABLE_SIZE; i++)
        if (hash_table[i].key != -1)
            linear_probing_search(hash_table[i]);

    printf("RESULT OF SIMULATION\n");
    printf("Loading density: %f\n", loading_density);
    printf("Number of samples: %d\n", number_of_samples);
    printf("Average number of comparisons: %f\n\n", (double)comparisons / number_of_samples);
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
    loaded++;
}

void linear_probing_search(Element item)
{
    int i, hash_value;
    i = hash_value = hash(item.key);

    while (hash_table[i].key != -1)
    {
        comparisons++;

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
