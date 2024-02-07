#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>

#include "constants.h"
#include "wordcount.h"
#include "simplelinkedlist.h"
#include "hashtable.h"

int main()
{
    printf("loading file...");

    // 1. Load the file "data.txt" into an array of strings
    char strings[TOTAL_STRINGS][STRING_LENGTH + 1]; // +1 for the null terminator

    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        perror("Unable to open file");
        return 1;
    }

    for (int i = 0; i < TOTAL_STRINGS; i++)
    {
        char buff[STRING_LENGTH + 2];
        fgets(buff, STRING_LENGTH + 2, file);
        buff[STRING_LENGTH] = '\0';
        strcpy(strings[i], buff);
    }
    fclose(file);

    printf("successful.\n");

    printf("processing...\n");

    // 2. Get the current time for computation start
    clock_t start = clock();

    // 3. Call the function 'run'
    runSimpleLinkedList(strings);
    // runHashTable(strings);

    // 4. Compute and output the total computational time
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total computational time: %.2f seconds\n", time_spent);

    FILE *ofile = fopen("output.txt", "w");
    if (file == NULL)
    {
        perror("Unable to open file");
        return 1;
    }

    for (int i = 0; i < size(); i++)
    {
        WordCount *wc = get(i);
        if (wc->count == FINISHED)
        {
            break;
        }

        fprintf(ofile, "%s, %d\n", wc->str, wc->count);
    }
    fclose(ofile);

    return 0;
}

// Empty stub for 'run'
void run(char (*array)[STRING_LENGTH + 1])
{
    printf("run called - does nothing\n");
}
