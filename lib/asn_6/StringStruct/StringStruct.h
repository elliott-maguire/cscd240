//
// Created by lltt on 6/5/20.
//

#ifndef CSCD240_STRINGSTRUCT_H
#define CSCD240_STRINGSTRUCT_H

typedef struct
{
    char *body;
    unsigned int length;
} String;

unsigned int length(String *s);

int compareString(String *a, String *b);

String *copyString(String *in);

String *makeString(char *in);

void freeString(String *s);

#endif //CSCD240_STRINGSTRUCT_H
