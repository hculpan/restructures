#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

#include <limits.h>

struct DynamicIntArray
{
    int size;
    int capacity;
    int resize;
    int *items;
};

const int NOVALUE;

struct DynamicIntArray *NewIntArray(int valCount, ...);

int Size(struct DynamicIntArray *array);
int Capacity(struct DynamicIntArray *array);

int AddItem(struct DynamicIntArray *array, int v);
int RemoveItem(struct DynamicIntArray *array, int v);
int GetItem(struct DynamicIntArray *array, int index);
int SetItem(struct DynamicIntArray *array, int index, int v);

int Compact(struct DynamicIntArray *array);

#endif