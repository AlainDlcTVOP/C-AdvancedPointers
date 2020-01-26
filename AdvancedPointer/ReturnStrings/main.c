#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAXSTRLEN 100

char *string_function(char *astring);

int main(int argc, char const *argv[])
{
    printf(string_function("Ida"));
    printf(string_function("Hagman idag nu"));
    return 0;
}
char *string_function(char *astring)
{
    char *s;
    s = (char *)malloc(MAXSTRLEN);
    s[0] = 0; // need this to initialize the buffer created by malloc
    strcat(s, "Hello ");
    strcat(s, astring);
    strcat(s, "\n");
    return s;
}