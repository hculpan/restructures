#include <stdio.h>
#include <strings.h>

#include "album.h"
#include "readdata.h"
#include "utils.h"

void displayMainPage();
void displayRecords();
void addRecord();

int main()
{
    readDataFile("./data.csv");

    bool running = true;
    while (running)
    {
        char buff[20];
        displayMainPage();
        scanf("%s", buff);
        lowerString(buff);
        if (strcmp("display", buff) == 0)
        {
            displayRecords();
        }
        else if (strcmp("add", buff) == 0)
        {
            addRecord();
        }
        else if (strcmp("quit", buff) == 0)
        {
            running = false;
        }
    }

    writeDataFile("./data.csv");
}

void displayMainPage()
{
    printf("*************************************************\n");
    printf("* Record Manager                                *\n");
    printf("*                                               *\n");
    printf("* <Display> records                             *\n");
    printf("* <Add> record                                  *\n");
    printf("*                                               *\n");
    printf("* <Quit>                                        *\n");
    printf("*************************************************\n");
}

void displayRecords()
{
    printf("\n\nDisplaying records:\n");
    struct Album *album = StartAlbumList();
    while (!IsEndOfList())
    {
        printf("%-50s %s, %d\n", album->title, album->artist, album->year);
        album = NextAlbum();
    }
    printf("\n\n");
}

void addRecord()
{
    char title[75];
    char artist[75];
    int year;

    // consume newline from command "add"
    fgets(title, 75, stdin);

    printf("\nAdding a record:\n");
    printf("  Title: ");
    fgets(title, 75, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character

    printf("  Artist: ");
    fgets(artist, 75, stdin);
    title[strcspn(artist, "\n")] = 0; // Remove newline character

    printf("  Year: ");
    scanf(" %d", &year);

    AddAlbum(title, artist, year);
}