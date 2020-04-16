// p_4.c
// ~~~~~
//
// A.K.A. "count_letters_digits.c"
//
// Contains a function to identify letters
// and numbers in a given string.
//
// Compile with: gcc -o cld p_4.c

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

#define MAX_INPUT 64

// Takes a single-line string input from the
// user and counts the number of letters
// and digits that appear in the string.
int main()
{
    int charCounts[26];
    for (int i = 0; i < 26; i++)
        charCounts[i] = 0;

    int digiCounts[10];
    for (int i = 0; i < 10; i++)
        digiCounts[i] = 0;

    char str[MAX_INPUT];

    printf("Type a string to evaluate (max %d characters):\n", MAX_INPUT);
    fgets(str, MAX_INPUT, stdin);

    int len = stringLength(str);

    char c;
    for (int i = 0; i < len; i++)
    {
        c = str[i];

        if (isLetter(c))
        {
            if (isUpper(c))
                c = lower(c);

            int j = c - 'a';
            charCounts[j]++;
        }
        else if (isDigit(c))
        {
            int j = c - '0';
            digiCounts[j]++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        printf(
            "character: %c appears %d times.\n",
            i + 'a',
            charCounts[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("digit: %c appears %d times\n", i + '0', digiCounts[i]);
    }

    return EXIT_SUCCESS;
}
