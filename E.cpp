#include "iostream"
#include "cstdio"

struct Comanda
    {
    long äùeffect;
    long num;
    };

void mergeSort (Comanda *start, Comanda *finish, Comanda* buffer);
void sliv (Comanda *arr1, Comanda *arr2, int sz1, int sz2, Comanda *buffer);

int main ()
    {
    int n = 0;
    scanf ("%d", &n);

    long eff      = 0;
    long max_eff  = 0;
    int num_min  = 0;
    int num_max  = 0;
    Comanda* buffer  = new Comanda [n];
    Comanda* arr     = new Comanda [n];

    for (int i = 0; i < n; i++)
        {
        scanf ("%ld", &arr[i].effect);
        arr[i].num = i + 1;
        }

    for (int i = 0; i < n; i++)
        printf ("%ld ", arr[n].effect);

    mergeSort (arr, arr + n, buffer);

    for (int i = 0, j = 0; i < n - 1; i++)
        {
        eff = arr[i].effect + arr[i + 1].effect;
        for (j = i + 2; j < n && arr[i].effect + arr[i + 1].effect >= arr[j].effect; j++)
            eff += arr [j].effect;
        if (max_eff < eff)
            {
            max_eff = eff;
            num_min = i;
            num_max = j;
            }
        }
    if (n > 1)
        {
        printf ("%ld\n", max_eff);

        for (int i = num_min; i < num_max; i++)
            arr[i].effect = arr[i].num;

        mergeSort (arr + num_min, arr + num_max, buffer);

        for (int i = num_min; i < num_max; i++)
            printf ("%ld ", arr[i].effect);
        }
    else
        printf ("%ld\n1", arr[0].effect);

    delete []arr;
    delete []buffer;
    return 0;
    }

void mergeSort (Comanda *start, Comanda *finish, Comanda* buffer)
    {
    if ((int)(finish - start) > 1)
        {
        mergeSort (start, start + ((int)(finish - start) + 1)/2,         buffer);
        mergeSort (       start + ((int)(finish - start) + 1)/2, finish, buffer);
        sliv (start, start + ((int)(finish - start) + 1)/2,
                             ((int)(finish - start) + 1)/2,
                             ((int)(finish - start))/2, buffer);
        }
    }

void sliv (Comanda *arr1, Comanda *arr2, int sz1, int sz2, Comanda* buffer)
    {
    int i = 0;
    int j = 0;

    for (;i + j < sz1 + sz2;)
        {
        if (i >= sz1)
            {
            for (;j < sz2; j++)
                {
                buffer [i + j].effect = arr2[j].effect;
                buffer [i + j].num    = arr2[j].num;
                }
            break;
            }
        if (j >= sz2)
            {
            for (;i < sz1; i++)
                {
                buffer [i + j].effect = arr1[i].effect;
                buffer [i + j].num    = arr1[i].num;
                }
            break;
            }

        if (arr1[i].effect > arr2[j].effect)
            {
            buffer [i + j].effect = arr2[j].effect;
            buffer [i + j].num    = arr2[j].num;
            j++;
            }
        else
            {
            buffer [i + j].effect = arr1[i].effect;
            buffer [i + j].num    = arr1[i].num;
            i++;
            }
        }

    for (int k = 0; k < sz1; k++)
        {
        arr1[k].effect = buffer[k].effect;
        arr1[k].num    = buffer[k].num;
        }
    for (int k = 0; k < sz2; k++)
        {
        arr2[k].effect = buffer[k + sz1].effect;
        arr2[k].num    = buffer[k + sz1].num;
        }
    }
