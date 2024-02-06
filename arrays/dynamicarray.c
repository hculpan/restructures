#include <stdlib.h>
#include <stdarg.h>

#include "dynamicarray.h"

const int NOVALUE = INT_MIN;

void growArray(struct DynamicIntArray *array);

struct DynamicIntArray *NewIntArray(int valCount, ...)
{
    struct DynamicIntArray *result = malloc(sizeof(struct DynamicIntArray));
    result->capacity = 0;
    result->size = 0;
    result->resize = 10;
    result->items = NULL;

    va_list args;
    va_start(args, valCount);
    for (int i = 0; i < valCount; i++)
    {
        AddItem(result, va_arg(args, int));
    }

    va_end(args);

    return result;
}

int AddItem(struct DynamicIntArray *array, int v)
{
    if (array->size == array->capacity)
    {
        growArray(array);
    }
    array->items[array->size] = v;
    array->size += 1;
    return array->size - 1;
}

int RemoveItem(struct DynamicIntArray *array, int v)
{
    if (array->size == 1) // If it's only got 1 element, we just make it effectively empty
    {
        array->size = 0;
    }
    else if (array->size > 0 && v >= 0 && v < array->size)
    {
        int n = array->items[v];
        array->size -= 1;
        for (int i = v; i < array->size; i++)
        {
            array->items[i] = array->items[i + 1];
        }
        return n;
    }

    return NOVALUE;
}

int SetItem(struct DynamicIntArray *array, int index, int v)
{
    if (index > -1 && index < array->size)
    {
        array->items[index] = v;
        return array->items[index];
    }

    return NOVALUE;
}

int GetItem(struct DynamicIntArray *array, int index)
{
    if (index > -1 && index < array->size)
    {
        return array->items[index];
    }

    return NOVALUE;
}

int Compact(struct DynamicIntArray *array)
{
    int *tmp = array->items;
    array->capacity = array->size;
    array->items = malloc(sizeof(int) * array->size);
    for (int i = 0; i < array->size; i++)
    {
        array->items[i] = tmp[i];
    }
    free(tmp);
    return array->size;
}

void growArray(struct DynamicIntArray *array)
{
    int *tmp = array->items;
    array->capacity += 10;
    array->items = malloc(sizeof(int) * array->capacity);
    for (int i = 0; i < array->size; i++)
    {
        array->items[i] = tmp[i];
    }
    free(tmp);
}

int Size(struct DynamicIntArray *array)
{
    return array->size;
}

int Capacity(struct DynamicIntArray *array)
{
    return array->capacity;
}