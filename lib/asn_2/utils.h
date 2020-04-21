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
    int result;

    if (c >= 'a' && c <= 'z')
        result = TRUE;
    else
        result = FALSE;

    return result;
}

int isUpper(char c)
{
    int result;

    if (c >= 'A' && c <= 'Z')
        result = TRUE;
    else
        result = FALSE;

    return result;
}

int isLetter(char c)
{
    int result;

    if (isLower(c) || isUpper(c))
        result = TRUE;
    else
        result = FALSE;

    return result;
}

int isDigit(char c)
{
    int result;

    if ((c >= '0' && c <= '9'))
        result = TRUE;
    else
        result = FALSE;

    return result;
}

int isWhitespace(char c)
{
    int result;

    if (c == ' ')
        result = TRUE;
    else
        result = FALSE;

    return result;
}

int stringLength(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
        ++i;

    return i;
}

char lower(char c)
{
    if (isUpper(c))
        return c + ('a' - 'A');
    else
        return c;
}

#endif //CSCD240_LIB_ASN_2_UTILS_H
