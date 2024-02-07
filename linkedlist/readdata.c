#include "readdata.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "album.h"

#define MAX_LINE_LENGTH 200
#define MAX_STRING_LENGTH 75

typedef struct
{
    char string1[MAX_STRING_LENGTH];
    char string2[MAX_STRING_LENGTH];
    int number;
} Record;

void readDataFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file))
    {
        // Removing newline character from line if present
        line[strcspn(line, "\n")] = 0;

        // Splitting the line into tokens
        char *token = strtok(line, ",");
        if (token == NULL)
            continue;

        Record record;

        // Parsing string1
        strncpy(record.string1, token, MAX_STRING_LENGTH - 1);
        record.string1[MAX_STRING_LENGTH - 1] = '\0'; // Ensuring null termination

        // Parsing string2
        token = strtok(NULL, ",");
        if (token != NULL)
        {
            strncpy(record.string2, token, MAX_STRING_LENGTH - 1);
            record.string2[MAX_STRING_LENGTH - 1] = '\0'; // Ensuring null termination
        }

        // Parsing integer
        token = strtok(NULL, ",");
        if (token != NULL)
        {
            record.number = atoi(token);
        }

        // Now you have a filled 'record', you can process it as needed
        // For example, just print it
        AddAlbum(record.string1, record.string2, record.number);
    }

    fclose(file);
}

void writeDataFile(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    struct Album *album = StartAlbumList();
    while (!IsEndOfList())
    {
        fprintf(file, "%s,%s,%d\n", album->title, album->artist, album->year);
        album = NextAlbum();
    }

    fclose(file);
}
