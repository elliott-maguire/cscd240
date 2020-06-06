//
// Created by lltt on 6/5/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

#include "mystring.h"

int stringlength(char *s)
{
    int i = 0;
    while (s[i++] != '\0')
        ;
    return i;
}

// stringcompare
// returns:
// 0 if equal
// 1 if left comes before right,
// -1 if right comes before left.
int stringcompare(char *left, char *right)
{
    for (; *left == *right; left++, right++)
    {
        if (*left == '\0')
        {
            return 0;
        }
    }

    // We exited. See what happened.
    if (*left < *right)
        return -1;
    if (*left > *right)
        return 1;
    return 0;
}

void stringcopy(char *p1, char *p2)
{
    while ((*p2++ = *p1++) != '\0')
    { // while *p1 != 0,
        ;
    }
}

/* *****************************
 * makestring
 * Allocate and copy a string.
 * Parameters:
 *  char* buffer - a zero-terminated string
 *      buffer to copy from.
 *
 * Returns:
 *  char* - a pointer to the new string
 *******************************/
char *makestring(char *buffer)
{
    char *new = malloc(stringlength(buffer));
    if (new <= 0)
        return 0;

    stringcopy(buffer, new);

    return new;
}

int getword(char *word, int lim, FILE *fp)
{
    int c;

    char *w = word;

    while (isspace(c = getc(fp)))
        ;
    if (c != EOF)
    {
        *w++ = c;
    }
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
    {
        if (!isalnum(*w = getc(fp)))
        {
            ungetc(*w, fp);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
