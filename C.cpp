#include "cstdio"
#include "iostream"

int main ()
    {
    int n = 22222222;

    FILE* f = std::fopen ("test.txt", "w");

    printf ("hello world");
    for (double i = 0; i < n; i++)
        fprintf (f, "%lg ", i * 243 + 324 + 0.5);
    }
