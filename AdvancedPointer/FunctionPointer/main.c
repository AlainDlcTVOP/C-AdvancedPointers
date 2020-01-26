#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*PFI)(int);
int square(int a);

int main()
{
    PFI test;
    char input[50];
    int value;
    int result;

    // set the funktion pointer to 'test' to the address of function 'square'
    test = square;

    printf("enter the number of square.... ");
    value = atoi(gets(input));
    result = test(value);
    printf("the result is %d  \n", result);

    return 0;
}
// ex
int square(int a)
{
    return a * a;
}