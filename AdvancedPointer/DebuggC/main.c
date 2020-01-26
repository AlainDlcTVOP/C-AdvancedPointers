#include <stdio.h>

/*This program display any
arguments that were passed to it
*/
int main(int argc, char const *argv[])
{
    int i;

    // (1) iterate over array of args
    for (int i = 0; i < argc; i++)
    {
        printf("arg %d is %s\n", i, argv[i]);
    }

    printf("\n\n");

    /* (2) dereference each string (*argv) via pointer to the pointer 
     to the start of the array of (**argv)*/

    for (i = 0; i < argc; i++)
    {
        printf("arg %d is %s\n", i, *argv);
        argv += 1;
    }
    return 0;
}
