#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_COUNT 200000
#define SEED_COUNT 20000
#define STRING_LENGTH 5

int main()
{
    FILE *file = fopen("output.txt", "w");
    if (file == NULL)
    {
        perror("Unable to open file");
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    char strArray[SEED_COUNT][STRING_LENGTH + 1];
    for (int i = 0; i < SEED_COUNT; i++)
    {
        for (int j = 0; j < STRING_LENGTH; j++)
        {
            strArray[i][j] = 'a' + rand() % 26; // Generate a random letter from 'a' to 'z'
        }

        strArray[i][STRING_LENGTH] = '\0'; // Null-terminate the string
    }

    for (int i = 0; i < TOTAL_COUNT; i++)
    {
        int index = rand() % SEED_COUNT;
        fprintf(file, "%s\n", strArray[index]);
    }

    fclose(file);

    printf("Data file generated successfully.\n");
    return 0;
}
