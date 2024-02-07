#include "wordcount.h"

#include <stdlib.h>
#include <strings.h>

WordCount **wordCounts = NULL;
int _size = 0;
int capacity = 0;

const int resize = 1000;

void initialize()
{
    if (wordCounts != NULL)
    {
        for (int i = 0; i < _size; i++)
        {
            free(wordCounts[i]);
        }
    }

    free(wordCounts);

    _size = 0;
    capacity = 0;
    wordCounts = NULL;
}

void grow()
{
    capacity += resize;
    WordCount **newWordCounts = malloc(sizeof(WordCount *) * capacity);
    for (int i = 0; i < _size; i++)
    {
        newWordCounts[i] = wordCounts[i];
    }
    free(wordCounts);
    wordCounts = newWordCounts;
}

void add(char str[STRING_LENGTH + 1], int count)
{
    if (_size == capacity)
    {
        grow();
    }
    wordCounts[_size] = malloc(sizeof(WordCount));
    strcpy(wordCounts[_size]->str, str);
    wordCounts[_size]->count = count;
    _size++;
}

void finish()
{
    add("", FINISHED);
}

int size()
{
    return _size;
}

WordCount *get(int index)
{
    if (index < 0 || index >= _size)
    {
        return NULL;
    }

    return wordCounts[index];
}