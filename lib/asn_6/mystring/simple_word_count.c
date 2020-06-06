// simple_word_count.c - Count the first n words in a file.
// compile with: gcc -o simple_word_count simple_word_count.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "mystring.h"

int main(int argc, char *argv[])
{
    char word_buf[WORD_BF_SZ] = {0};

    // an array of words (strings)
    char *word_array[WORD_ARRAY_SZ];
    int num_words = 0;
    char *file_name;

    // This is a stream pointer.
    FILE *fp_rd;
    int fd_rd = -1; // file descriptor

    // get the file name and open it.
    if (argc >= 2)
    {
        file_name = makestring(argv[1]);
        if (file_name == 0)
        {
            perror("makestring faled to allocate a string.");
            return EXIT_FAILURE;
        }
        stringcopy(argv[1], file_name);
    }
    else
    {
        printf("simple word counter\n\tusage: simple_wc <<input_file>>\n");
    }

    // open a file stream.
    // first we will get the file descriptor,
    // then get a stream pointer to the open file
    if ((fd_rd = open(file_name, O_RDONLY)) == -1)
    {
        perror("read");
        return EXIT_FAILURE;
    }
    fp_rd = fdopen(fd_rd, "r");

    // read words and check if the word is already in word_array.
    //   or if word_array is full.
    while (getword(word_buf, WORD_BF_SZ, fp_rd) != EOF && num_words < WORD_ARRAY_SZ)
    {
        char *word = makestring(word_buf);
        int found = FALSE;
        for (int i = 0; i < num_words; i++)
        {
            if (stringcompare(word_array[i], word) == 0)
            {
                found = TRUE;
                break;
            }
        }
        if (found == FALSE)
        {
            // We need to add another word to the list
            word_array[num_words] = word;
            num_words++;
        }
    }

    // Let's print the list to stdout
    for (int i = 0; i < num_words; i++)
    {
        printf("%s\n", word_array[i]);
    }

    // close the input file and clean up.
    close(fd_rd);
    free(file_name);

    for (int i = 0; i < num_words; i++)
    {
        free(word_array[i]);
    }

    return EXIT_SUCCESS;
}