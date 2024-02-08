#include "hashtable.h"

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "wordcount.h"

#define TABLE_SIZE 20000

WordCount **table;

int hashCode(char str[STRING_LENGTH + 1]);
void setValue(char str[STRING_LENGTH + 1]);
int getValue(char str[STRING_LENGTH + 1]);
int findTableIndex(char key[STRING_LENGTH + 1]);

int collisionCount = 0;

void runHashTable(char (*array)[STRING_LENGTH + 1])
{
    table = malloc(sizeof(WordCount *) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }

    for (int i = 0; i < TOTAL_STRINGS; i++)
    {
        setValue(array[i]);
    }

    initialize();

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != NULL)
        {
            add(table[i]->str, table[i]->count);
        }
    }

    finish();
}

int getValue(char key[STRING_LENGTH + 1])
{
    int index = findTableIndex(key);
    if (table[index] == NULL)
    {
        return 0;
    }

    return table[index]->count;
}

void setValue(char key[STRING_LENGTH + 1])
{
    int index = findTableIndex(key);
    if (table[index] == NULL)
    {
        table[index] = malloc(sizeof(WordCount));
        strcpy(table[index]->str, key);
        table[index]->count = 1;
    }
    else
    {
        table[index]->count++;
    }
}

int findTableIndex(char key[STRING_LENGTH + 1])
{
    int index = hashCode(key) % TABLE_SIZE;
    if (table[index] == NULL || strcmp(table[index]->str, key) == 0)
    {
        return index;
    }

    collisionCount++;
    printf("collision %d with %s\n", collisionCount, key);
    while (1)
    {
        index++;
        if (index >= TABLE_SIZE)
        {
            index = 0;
        }

        if (table[index] == NULL || strcmp(table[index]->str, key) == 0)
        {
            return index;
        }
    }
}

int hashCode(char str[STRING_LENGTH + 1])
{
    int h = 0;
    for (int i = STRING_LENGTH - 1; i >= 0; i--)
    {
        h = (31 * h) + str[i];
    }

    return h;
}
