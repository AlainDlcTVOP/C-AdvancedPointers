#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// look at calloc and memory leaks

int main()
{
    char *s;
    int i;
    int *p;

    // use malloc first to allocate some memory and see what is in it (usually rubbish)

    s = (char *)malloc(6);
    for (i = 0; i < 6; i++)
        printf("s[%d]=%d\n", i, s[i]);
    free(s);

puts("-------------------------------------------");
    // calloc will zeroed out
    s = (char *)calloc(6, sizeof(char));
    for (i = 0; i < 6; i++)
        printf("s[%d]=%d\n", i, s[i]);
    free(s);

    // clalloc allocates 6 int or 24 bytes since the int is 4 bytes long
puts("-------------------------------------------");
    p = (char *)calloc(6, sizeof(char));
    for (i = 0; i < 6; i++)
        printf("s[%d]=%d\n", i, p[i]);
    free(p);

    return 0;
}