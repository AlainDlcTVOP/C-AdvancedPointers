#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str1[] = "Hello"; // The array is store in diffrent addres a value
    char *str2 = "Goodbye"; // str2 points the address where is memory location
    str2 = str1;
    printf("%d %d %s\n ", &str1, str1, str1);
    printf("%d %d %s\n ", &str2, str2, str2);
     

    return 0;
}
