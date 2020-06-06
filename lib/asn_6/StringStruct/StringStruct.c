//
// Created by lltt on 6/5/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StringStruct.h"

unsigned int length(String *s)
{
    return s->length;
}

int compareString(String *a, String *b)
{
    return strncmp(a->body, b->body, a->length);
}

String *copyString(String *in)
{
    String *out = makeString(in->body);

    return out;
}

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
