// p_1.c
// ~~~~~
//
// A.K.A. "cat1.c"
//
// Contains a function that is a simple
// clone of the UNIX `cat` command.
//
// Compile with: gcc -o cat1 p_1.c

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
        printf("better_copy:\n\tusage: better_copy <<in_file_path>>\n");
        return EXIT_FAILURE;
    }

    int file = open(in, O_RDONLY);

    long int rd_size = -1;
    long int wt_size = -1;
    while ((rd_size = read(file, buffer, MAX_BUFFER_SIZE - 1)) > 0)
    {
        buffer[rd_size] = '\0';
        printf("%s\n", buffer);
    }

    int cr = close(file);

    return EXIT_SUCCESS;
}
