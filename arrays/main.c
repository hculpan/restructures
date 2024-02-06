#include <stdio.h>

#include "dynamicarray.h"

int main()
{
    struct DynamicIntArray *a = NewIntArray(11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);

    if (a == NULL)
    {
        printf("array invalid\n");
        return 1;
    }

    if (Size(a) != 11)
    {
        printf("expected size 11, got %d\n", Size(a));
        return 1;
    }

    if (Capacity(a) != 20)
    {
        printf("expected capacity 20, got %d\n", Capacity(a));
        return 1;
    }

    if (GetItem(a, 3) != 4)
    {
        printf("expected value 4 at index 3, got %d\n", GetItem(a, 3));
        return 1;
    }

    if (GetItem(a, 12) != NOVALUE)
    {
        printf("expected NOVALUE at index 12, got %d\n", GetItem(a, 12));
        return 1;
    }

    int n = AddItem(a, 100);
    if (n != 11)
    {
        printf("expected return from AddItem of 11, got %d\n", n);
        return 1;
    }

    if (Size(a) != 12)
    {
        printf("expected size 12, got %d\n", Size(a));
        return 1;
    }

    if (Capacity(a) != 20)
    {
        printf("expected capacity 20, got %d\n", Capacity(a));
        return 1;
    }

    if (GetItem(a, 11) != 100)
    {
        printf("expected value 100 at index 11, got %d\n", GetItem(a, 11));
        return 1;
    }

    n = SetItem(a, 11, 200);
    if (n != 200 || GetItem(a, 11) != 200)
    {
        printf("setitem: expected value 200 at index 11, got %d\n", GetItem(a, 11));
        return 1;
    }

    n = RemoveItem(a, 11);
    if (n != 200)
    {
        printf("removeitem: expected value 200, got %d\n", n);
        return 1;
    }

    if (Size(a) != 11)
    {
        printf("expected size 11, got %d\n", Size(a));
        return 1;
    }

    if (Capacity(a) != 20)
    {
        printf("expected capacity 20, got %d\n", Capacity(a));
        return 1;
    }

    if (GetItem(a, 11) != NOVALUE)
    {
        printf("expected NOVALUE at index 11, got %d\n", GetItem(a, 11));
        return 1;
    }

    n = RemoveItem(a, 0);
    if (n != 1)
    {
        printf("removeitem: expected value 1, got %d\n", n);
        return 1;
    }

    if (Size(a) != 10)
    {
        printf("expected size 11, got %d\n", Size(a));
        return 1;
    }

    if (Capacity(a) != 20)
    {
        printf("expected capacity 20, got %d\n", Capacity(a));
        return 1;
    }

    if (GetItem(a, 10) != NOVALUE)
    {
        printf("expected NOVALUE at index 10, got %d\n", GetItem(a, 10));
        return 1;
    }

    if (GetItem(a, 0) != 2)
    {
        printf("expected 0 at index 2, got %d\n", GetItem(a, 2));
        return 1;
    }

    n = Compact(a);
    if (n != 10)
    {
        printf("compact: expected value 10, got %d\n", n);
        return 1;
    }

    if (Size(a) != 10)
    {
        printf("expected size 11, got %d\n", Size(a));
        return 1;
    }

    if (Capacity(a) != 10)
    {
        printf("expected capacity 10, got %d\n", Capacity(a));
        return 1;
    }

    printf("All tests executed: Status OK\n");
}