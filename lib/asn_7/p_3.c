/**
 * Problem 3
 * ~~~~~~~~~
 *
 * Write a program that opens a file and reads the text from it.
 * The program then counts the number of vowels found in the file
 * and prints them out.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define MAX_INPUT_SIZE 256
#define MAX_BUFFER_SIZE 1024

char isVowel(char c)
{
    char lowercase = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    char uppercase = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (lowercase || uppercase)
        return TRUE;

    return FALSE;
}

int main(int argc, char *argv[])
{
    int file, vowelCount;
    long int readSize, writeSize;
    char path[MAX_INPUT_SIZE], buffer[MAX_BUFFER_SIZE];

    strcpy(path, argv[1]);

    file = open(path, O_RDONLY);

    readSize = -1;
    writeSize = -1;
    vowelCount = 0;
    while ((readSize = read(file, buffer, MAX_BUFFER_SIZE - 1)) > 0)
    {
        buffer[readSize] = '\0';

        for (int i = 0; i < readSize; i++)
        {
            if (isVowel(buffer[i]))
                vowelCount++;
        }
    }

    printf("Number of Vowels: %d\n", vowelCount);

    return EXIT_SUCCESS;
}
