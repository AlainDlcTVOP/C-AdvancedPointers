#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 4

int main(int argc, char const *argv[])
{
    int *p;
    int a[COUNT];
    printf("size of an 'int' is %d\n", sizeof(int));
    // initailaize our array
    for (int i = 0; i < COUNT; i++)
        a[i] = i;
        
    // let's do some pointer arithmetic
    p = a;
    printf("address of a is %p; value of p is %p [%d]; value pointed to p is %d\n", a, p, p, p, *p);

    p = p + 1;
    printf("address of a is %p; value of p is %p [%d]; value pointed to p is %d\n", a, p, p, p, *p);

    // incremet p by another 2 value pointed by 'p' is now a[3]
    p = p + 2;

    // what happens if we go beyond the array end? there's nothing to stop your or warn you...

    p = p + 1;
    printf("address of a is %p; value of p is %p [%d]; value pointed to p is %d\n", a, p, p, p, *p);
    return 0;
}
