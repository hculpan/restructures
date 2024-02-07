#ifndef _WORD_COUNT_H_
#define _WORD_COUNT_H_

#include "constants.h"

#define FINISHED -1

typedef struct WordCount WordCount;

struct WordCount
{
    char str[STRING_LENGTH + 1];
    int count;
};

void initialize();
void finish();

void add(char str[STRING_LENGTH + 1], int count);
int size();
WordCount *get(int index);

#endif