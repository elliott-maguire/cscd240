/**
 * Problem 2
 * ~~~~~~~~~
 *
 * Write a program that takes a string on the command line
 * and prints the string in reverse.
 *
 * Prompt notes that it shouldn't support spaces, which
 * I assume is to restrict use of the standard `strrev` function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int inCount, outCount, length;
    char *inString, *outString;

    strcpy(inString, argv[1]);
    length = strlen(inString);
    outString = (char *)malloc(length);

    outCount = 0;
    for (inCount = length - 1; inCount > -1; inCount--)
    {
        outString[outCount] = inString[inCount];
        outCount++;
    }

    printf("%s\n", outString);

    free(outString);

    return EXIT_SUCCESS;
}