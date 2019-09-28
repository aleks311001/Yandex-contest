#include "random"
#include "cstdio"

int main ()
    {
    for (int i = 0; i < 100000; i++)
        printf ("%ld ", rand());

    return 0;
    }
