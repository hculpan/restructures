#include "album.h"

#include <stdlib.h>
#include <string.h>

struct Album *album_head = NULL;
struct Album *album_tail = NULL;

struct Album *iterator = NULL;
bool reachedEndOfList = false;
bool reachedStartOfList = false;

void AddAlbum(char *title, char *artist, int year)
{
    struct Album *new = malloc(sizeof(struct Album));
    new->title = malloc(strlen(title));
    strcpy(new->title, title);
    new->artist = malloc(strlen(artist));
    strcpy(new->artist, artist);
    new->year = year;
    new->next = NULL;
    new->prev = NULL;

    if (album_head == NULL && album_tail == NULL) // we have an empty list
    {
        album_head = new;
        album_tail = new;
    }
    else
    {
        album_tail->next = new;
        new->prev = album_tail;
        album_tail = new;
    }
}

struct Album *StartAlbumList()
{
    reachedStartOfList = false;
    reachedEndOfList = false;
    iterator = album_head;
    return iterator;
}

struct Album *TailAlbumList()
{
    reachedStartOfList = false;
    reachedEndOfList = false;
    iterator = album_tail;
    return iterator;
}

struct Album *PrevAlbum()
{
    iterator = iterator->prev;
    return iterator;
}

struct Album *NextAlbum()
{
    iterator = iterator->next;
    return iterator;
}

bool IsEndOfList()
{
    bool result = reachedEndOfList;
    reachedEndOfList = (iterator == album_tail);
    return result;
}

bool IsStartOfList()
{
    bool result = reachedStartOfList;
    reachedStartOfList = (iterator == album_head);
    return result;
}