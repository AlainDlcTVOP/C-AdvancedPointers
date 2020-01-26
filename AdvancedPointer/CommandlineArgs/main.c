#include <stdio.h>

/*This program display any
  arguments that were pass to it */

int main(int argc, char **argv)
{
    int i = 0;
    // (1) iterate over array of args

    for (; i < argc; i++)
    {
        printf("arg %d is %s\n", i, argv[i]);
    }
    printf("\n\n");

    /* (2) dereference each string arg (*argv) via pointer to the pointer
        to the start of the array of args (**argv)*/

    for (; i < argc; i++)
    {
        printf("arg %d is %s\n", i, *argv); // prints arg pointer to by argv
    }

    return 0;
}
