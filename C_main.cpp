#include "cstdio"
#include "iostream"
#include "ctime"

void WriteFileDouble (FILE* f, int n);
double TimeReadF (int n, void (*f)(double&));
void F_cin (double& t);
void F_scanf (double& t);

int main (int argc, char* argv[])
    {
    if (argc == 1) printf ("Please, choose function");
    else
        {
        if (argv[1][0] == 'w')
            {
            FILE* f = std::fopen ("test.txt", "w");
            WriteFileDouble (f, 22222222);
            fclose (f);
            }
        else
            {
            freopen ("test.txt", "r", stdin);

            if (argv[1][0] == 'c')
                for (int n = 10000; n < 100000000; n *= 10)
                    printf ("std::cin (n = %d): %lg\n", n, TimeReadF (n, F_cin  ));
            if (argv[1][0] == 's')
                for (int n = 10000; n < 100000000; n *= 10)
                    printf ("scanf (n = %d): %lg\n",    n, TimeReadF (n, F_scanf));

            fclose (stdin);
            }
        }
    }

void WriteFileDouble (FILE* f, int n)
    {
    for (double i = 0; i < n; i++)
        fprintf (f, "%lg ", i * 243 + 324 + 0.5);
    }

double TimeReadF (int n, void (*f)(double&))
    {
    double t = 0;
    clock_t start = clock();

    for (int i = 0; i < n; i++)
        f (t);

    return (clock() - start) / (double)CLOCKS_PER_SEC;
    }

void F_cin (double& t)
    {
    std::cin >> t;
    }

void F_scanf (double& t)
    {
    scanf ("%lg", &t);
    }
