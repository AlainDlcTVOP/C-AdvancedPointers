#include <stdio.h>

struct
{
    int ***ippp;
    int **ipp;
    int *ip;
    int i;
} p;

/* This shows pointers to other pointers
    and shold be used in conjunction with the memory window */

int main(int ac, char **av)
{
    p.ippp = &p.ipp;
    p.ipp = &p.ip;
    p.ip = &p.i;
    p.i = 0x55555555; // so we can recognise what we're pointing to
    return 0;
}
