#include <stdio.h>
#define LENGTH 3

char *words[LENGTH]; // some strings

int main(int argc, char const *argv[])
{
    char *pc;   // a pointer to a character
    char **ppc; // a pointer to a pointer to a character

    printf("multiple inirection example\n");

    // initialize our string array
    words[0] = "zero";
    words[1] = "one";
    words[2] = "two";

    for (int i = 0; i < LENGTH; i++)
    {
        printf("%s\n", words[i]);
    }

    /*
     B: apointer to an array of strings
     the sama as a pointer to a pointer to a character
    */

    printf("\nNow print the chars in each strings.....\n");
    ppc = words; // initialize the pointer to a pointer to a character
    for (int i = 0; i < LENGTH; i++) // loop over each string
    {

        ppc = words + i;
        pc = *ppc;
        while (*pc != 0)  // process each character in a string
        {
            printf("%c ", *pc); // print out each character of the string individual
            pc++;
        }
        printf("\n");
    }

    return 0;
}
