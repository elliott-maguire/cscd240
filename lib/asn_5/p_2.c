// p_2.c
// ~~~~~
//
// Compile with: gcc -o p_2 p_2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *body;
    unsigned int length;
} String;

String *makeString(char *in)
{
    String *str = (String *)malloc(sizeof(String));

    str->length = strlen(in);

    str->body = (char *)malloc(str->length * sizeof(char)),
    strcpy(str->body, in);

    return str;
}

void freeString(String *s)
{
    free(s->body);
    free(s);
}

int main()
{
    char *str = "Hello World";
    String *hello = makeString(str);

    printf(
        "the String hello contains %s which is %u in length\n",
        hello->body,
        hello->length);

    freeString(hello);

    return EXIT_SUCCESS;
}
