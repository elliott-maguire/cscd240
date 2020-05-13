// p_1.c
// ~~~~~
//
// A.K.A. "pointer_copy.c"
//
// Contains a function that is a simple
// clone of the UNIX `cat` command.
//
// This file is a clone of the solution to problem 2
// of assignment 3, but utilizes malloc to allocate
// the memory for the buffer.
//
// Compile with: gcc -o pc p_2.c

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    char in[200] = "";
    char *buffer = (char *)malloc(MAX_BUFFER_SIZE);

    if (argc >= 2)
    {
        strcpy(in, argv[1]);
    }
    else
    {
        return EXIT_FAILURE;
    }

    int file = open(in, O_RDONLY);

    long int read_size = -1;
    long int write_size = -1;
    while ((read_size = read(file, buffer, MAX_BUFFER_SIZE - 1)) > 0)
    {
        buffer[read_size] = '\0';
        if ((write_size = write(STDOUT_FILENO, buffer, read_size) > 0))
        {
            write(STDOUT_FILENO, buffer, write_size);
        }
    }

    int cr = close(file);

    return EXIT_SUCCESS;
}
