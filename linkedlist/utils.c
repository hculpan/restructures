#include "utils.h"

#include <ctype.h>

void lowerString(char *str)
{
    for (; *str; ++str)
        *str = tolower(*str);
}