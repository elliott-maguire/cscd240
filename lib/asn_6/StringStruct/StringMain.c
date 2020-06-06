//
// Created by lltt on 6/5/20.
//

#include <stdio.h>

#include "StringStruct.h"

int main(void)
{
    char *s = "Time flies like an arrow. Fruit flies like a banana.";

    String *e = makeString(s);

    printf("The example string is %u bytes long.\n", length(e));

    String *c = copyString(e);
    printf("Example:\n%s\n\ncopy:\n%s\n", e->body, c->body);

    String *s1 = makeString("string1");
    String *s2 = makeString("string2");
    printf("String comparison of \n%s\nand\n%s\n is %d\n",
           s1->body,
           s2->body,
           compareString(s1, s2));
}