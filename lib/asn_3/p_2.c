// p_2.c
// ~~~~~
//
// A.K.A. "cat2.c"
//
// Contains a function that is a simple
// clone of the UNIX `cat` command with a pipe.
//
// Compile with: gcc -o cat2 p_2.c

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
    char buffer[MAX_BUFFER_SIZE];

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

    close(file);

    return EXIT_SUCCESS;
}
