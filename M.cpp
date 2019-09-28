#include <iostream>
#include <stdio.h>
#include <assert.h>

long long mergeSort (int *start, int *finish, int* buffer);
long long sliv (int *arr1, int *arr2, int sz1, int sz2, int *buffer);

int main ()
    {
    int n = 0;
    scanf ("%d", &n);

    int* arr = new int[n];
    int* buffer = new int[n];
    for (int i = 0; i < n; i++)
        {
        scanf ("%d", arr + i);
        }

    long long inv = 0;
    inv = mergeSort (arr, arr + n, buffer);

    printf ("%lld", inv);
    }

long long mergeSort (int *start, int *finish, int* buffer)
    {
    int lenth = (int)(finish - start);
    long long n1 = 0;
    long long n2 = 0;
    long long n3 = 0;
    if (lenth > 1)
        {
        n1 = mergeSort (start, start + (lenth + 1)/2,         buffer);
        //printf ("%d|", n1);
        n2 = mergeSort (       start + (lenth + 1)/2, finish, buffer);
        //printf ("%d|", n2);
        n3 = sliv (start, start + (lenth + 1)/2, (lenth + 1)/2, lenth/2, buffer);
        //printf ("%d|", n3);
        }
    return n1 + n2 + n3;
    }

void PrintArr (int *arr, int n)
    {
    for (int i = 0; i < n; i++)
        {
        printf ("arr[%d] = %d | ", i, arr[i]);
        }
    printf ("\n");
    }

long long sliv (int *arr1, int *arr2, int sz1, int sz2, int *buffer)
    {
    int i = 0;
    int j = 0;
    long long n = 0;

    for (; i < sz1; i++)
        {
        for (; j < sz2 && arr1[i] > arr2[j]; j++) {}
        n += j;
        }

    i = 0;
    j = 0;
    for (;i + j < sz1 + sz2;)
        {
        if (i >= sz1)
            {
            for (;j < sz2; j++)
                {
                buffer [i + j] = *(arr2 + j);
                }
            break;
            }
        if (j >= sz2)
            {
            for (;i < sz1; i++)
                {
                buffer [i + j] = *(arr1 + i);
                }
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

    return n;
    }
