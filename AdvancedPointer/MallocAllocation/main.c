#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// very simple allocation of momory and changing something in the newly allocated memory
int main(int argc, char const *argv[])
{
    char *s;
    int stringsize;

    stringsize = sizeof("hell");                  // first works out how big it is
    printf("size of 'hello' is %d\n", stringsize); // note that it is SIX bytes long (not five)

    s = (char *)malloc(stringsize); // now allocate some memory of sufficient size to hold the string
    if (s == NULL)                  // note the cast '(char*)' This is required because malloc always
    {
        printf("malloc failed"); // malloc will return 0 (NULL) if it failed
        exit(0);
    }

    // now copy the string inte newly allocated memory
    strncpy(s, "hell", stringsize);

    // and change the first character (just to show we can)
    printf("s is %s\n", s);
    s[0] = 'c';
    printf("s is now %s\n", s);
    free(s);
    return 0;
}
