#include "cstdio"

void mergeSort (int *start, int *finish, int* buffer);
void sliv (int *arr1, int *arr2, int sz1, int sz2, int *buffer);

int main ()
    {
    int n = 0;
    int m = 0;

    scanf ("%d%d", &n, &m);

    int *arr = new int[m*n];
    int *buffer = new int [m*n];

    for (int i = 0; i < n*m; i++)
        scanf ("%d", arr + i);

    for (int i = 0; i < n; i++)
        mergeSort (arr + i*m, arr + (i + 1)*m, buffer);

    for (int i = 0; i < n - 1; i++)
        sliv (arr, arr + (i + 1)*m, (i + 1)*m, m, buffer);

    for (int i = 0; i < m*n; i++)
        printf ("%d ", *(arr + i));

    delete []arr;
    delete []buffer;
    }

void mergeSort (int *start, int *finish, int* buffer)
    {
    int lenth = (int)(finish - start);
    if (lenth > 1)
        {
        mergeSort (start, start + (lenth + 1)/2,         buffer);
        mergeSort (       start + (lenth + 1)/2, finish, buffer);
        sliv (start, start + (lenth + 1)/2, (lenth + 1)/2, lenth/2, buffer);
        }
    }

void sliv (int *arr1, int *arr2, int sz1, int sz2, int *buffer)
    {
    int i = 0;
    int j = 0;

    for (;i + j < sz1 + sz2;)
        {
        if (i >= sz1)
            {
            for (;j < sz2; j++)
                buffer [i + j] = *(arr2 + j);
            break;
            }
        if (j >= sz2)
            {
            for (;i < sz1; i++)
                buffer [i + j] = *(arr1 + i);
            break;
            }

        if (*(arr1 + i) > *(arr2 + j))
            {
            buffer [i + j] = *(arr2 + j);
            j++;
            }
        else
            {
            buffer [i + j] = *(arr1 + i);
            i++;
            }
        }

    for (int k = 0; k < sz1; k++) *(arr1 + k) = buffer[k];
    for (int k = 0; k < sz2; k++) *(arr2 + k) = buffer[sz1 + k];
    }
