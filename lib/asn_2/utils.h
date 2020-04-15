// find_letters_numbers.h
// ~~~~~~~~~~~~~~~~~~~~~~
//
// This is a header file that contains functions
// used in the find_letters_numbers main function.

#ifndef CSCD240_UTILS_H
#define CSCD240_UTILS_H

#define TRUE  1
#define FALSE 0

int isLower(char c) {
    if (c >= 'a' && c <= 'z')
        return TRUE;
    else
        return FALSE;
}

int isUpper(char c) {
    if (c >= 'A' && c <= 'Z')
        return TRUE;
    else
        return FALSE;
}

int isLetter(char c) {
    if (isLower(c) || isUpper(c))
        return TRUE;
    else
        return FALSE;
}

int isDigit(char c) {
    if ((c >= '0' && c <= '9'))
        return TRUE;
    else
        return FALSE;
}

int stringLength(const char* str) {
    int i = 0;
    while (str[i] != '\0')
        ++i;

    return i;
}

#endif //CSCD240_UTILS_H
