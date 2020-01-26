#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *p;
    int a[] = {100, 200, 300, 400};
    p = a;
    for (int i = 0; i < 4; i++)
    {
        printf("Value = %d, Address = %d\n", *p, p);
        p = p + 1;
    }
}
