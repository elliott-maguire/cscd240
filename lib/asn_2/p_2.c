// p_2.c
// ~~~~~~~~~~~
//
// A.K.A. "find_letters_ascii_codes.c"
//
// Contains a function to print an ASCII table
// of the different values of input characters.
//
// Compile with: gcc -o flac p_2.c

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

#define MAX_INPUT 64

// Takes a single-line string input from the
// user and evaluates each character present
// as either a letter, digit, or other.
int main()
{
    char str[MAX_INPUT];

    printf("Type a string to evaluate (max %d characters):\n", MAX_INPUT);
    fgets(str, MAX_INPUT, stdin);

    int len = stringLength(str);

    char c;
    for (int i = 0; i < len; i++)
    {
        c = str[i];

        if (isLetter(c))
            printf("LETTER: %3d %#6o %#6x %6c \n", c, c, c, c);
        else if (isDigit(c))
            printf("DIGIT: %4d %#6o %#6x %6c \n", c, c, c, c);
        else
            printf("OTHER: %4d %#6o %#6x %6c \n", c, c, c, c);
    }

    return EXIT_SUCCESS;
}
