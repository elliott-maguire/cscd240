// problem_1.c
// ~~~~~~~~~~~
//
// A.K.A. "find_letters_numbers.c"
//
// Contains a function to identify letters
// and numbers in a given string.
//
// Compile with: gcc -o fln problem_1.c

#include <stdio.h>
#include "utils.h"

#define MAX_INPUT 64

// Takes a single-line string input from the
// user and evaluates each character present
// as either a letter, digit, or other.
int main() {
    char str[MAX_INPUT];

    printf("Type a string to evaluate (max %d characters):\n", MAX_INPUT);
    fgets(str, MAX_INPUT, stdin);

    int len = stringLength(str);

    char c;
    for (int i = 0; i < len; i++) {
        c = str[i];

        if (isLetter(c))
            printf("LETTER: %2c\n", c);
        else if (isDigit(c))
            printf("DIGIT: %3c\n", c);
        else
            printf("OTHER: %3c\n", c);
    }
}
