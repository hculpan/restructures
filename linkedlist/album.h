#ifndef _ALBUM_H_
#define _ALBUM_H_

#include <stdbool.h>

struct Album
{
    char *title;
    char *artist;
    int year;

    struct Album *next;
    struct Album *prev;
};

void AddAlbum(char *title, char *artist, int year);

struct Album *StartAlbumList();
struct Album *NextAlbum();
bool IsEndOfList();
struct Album *TailAlbumList();
struct Album *PrevAlbum();
bool IsStartOfList();

#endif