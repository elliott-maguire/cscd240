// p_1.c
// ~~~~~
//
// Compile with: gcc -o p_1 p_1.c

#include <stdio.h>
#include <stdlib.h>

/**
 * I've used a more idiomatic ternary conditional
 * to shrink and clean up this function.
 */
void lower(char *s)
{
    while (*s)
    {
        *s = (*s > 'A' && *s <= 'Z') ? *s + 32 : *s;
        s++;
    }
}

int search(char *s, char c)
{
    int i = 0;
    while (*s)
    {
        if (*s == c)
            return i;

        s++;
        i++;
    }

    return -1;
}

int main()
{
    char str[] = "Hello World";

    lower(str);
    printf("%s\n", str);

    printf("%d should be 0\n", search(str, 'h'));
    printf("%d should be 4\n", search(str, 'o'));
    printf("%d should be -1\n", search(str, 'x'));

    return EXIT_SUCCESS;
}
