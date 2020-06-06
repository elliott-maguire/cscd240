//
// Created by lltt on 6/5/20.
//

#ifndef CSCD240_MYSTRING_H
#define CSCD240_MYSTRING_H

#define FILE_BF_SZ 1024
#define WORD_ARRAY_SZ 100
#define WORD_BF_SZ 100

#define TRUE 1
#define FALSE 0

int stringlength(char* s);

int stringcompare(char* left, char* right);

void stringcopy(char* p1, char* p2);

char* makestring(char* buffer);

int getword(char* word, int lim, FILE* fp);

#endif //CSCD240_MYSTRING_H
