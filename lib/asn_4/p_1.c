// p_1.c
// ~~~~~
//
// A.K.A. "stringlength.c"
//
// Contains a function that uses a simple
// pointer to evaluate thet length of a string.
//
// Compile with: gcc -o stringlength p_1.c

#include <stdlib.h>
#include <stdio.h>

#define MAX_INPUT 64

int stringLength(char *str)
{
    char *pt;
    pt = str;

    int i = 0;
    while (*pt != '\0')
    {
        ++i;
        ++pt;
    }

    return i;
}

int main()
{
    char str[MAX_INPUT];

    printf("Type a string to evaluate (max %d characters):\n", MAX_INPUT);
    fgets(str, MAX_INPUT, stdin);

    int len = stringLength(str);

    printf("The length of the string is %d.\n", len);

    return EXIT_SUCCESS;
}
