#include "cstdio"

unsigned int findRepetitionsCount(const char* s, char c1, char c2);

int main ()
    {
    char *s = new char[1000000];
    char c1 = 0;
    char c2 = 0;

    scanf ("%s ", s);
    scanf ("%c %c", &c1, &c2);

    printf ("%d", findRepetitionsCount (s, c1, c2));

    delete []s;
    return 0;
    }

unsigned int findRepetitionsCount(const char* s, char c1, char c2)
    {
    unsigned int fRC = 0;

    for (int i = 0; i < 1000000 && s[i] != 0; i++)
        {
        if (s[i] == c1)
            {
            if (s[i + 1] == c2)
                {
                fRC++;
                }
            }
        }

    return fRC;
    }
