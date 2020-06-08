/**
 * Problem 1
 * ~~~~~~~~~
 *
 * Write a main function that takes in a command line parameter
 * that is a decimal number. The program should print the circumference
 * and area of a circle with that number as its radius.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.141592

int main(int argc, char *argv[])
{
    float area, circumference, radius;

    radius = atof(argv[1]);

    area = PI * (radius * radius);
    circumference = radius * 2;

    printf("Radius: %f\n", radius);
    printf("Area: %f\n", area);
    printf("Circumference: %f\n", circumference);

    return EXIT_SUCCESS;
}