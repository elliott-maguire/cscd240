// utils.h
// ~~~~~~~
//
// This is a header file that contains functions
// used in assignment 2 solutions.

#ifndef CSCD240_LIB_ASN_2_UTILS_H
#define CSCD240_LIB_ASN_2_UTILS_H

#define TRUE 1
#define FALSE 0

int isLower(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int isUpper(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int isLetter(char c)
{
    if (isLower(c) || isUpper(c))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int isDigit(char c)
{
    if ((c >= '0' && c <= '9'))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int isWhitespace(char c)
{
    if (c == ' ')
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int stringLength(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        ++i;
    }

    return i;
}

char lower(char c)
{
    if (isUpper(c))
    {
        return c + ('a' - 'A');
    }
    else
    {
        return c;
    }
}

#endif //CSCD240_LIB_ASN_2_UTILS_H
