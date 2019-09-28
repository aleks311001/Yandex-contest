#include <iostream>
#include <stdio.h>

struct otr
    {
    int p;
    int flag_l;
    int num;
    };

void Scan_otr (otr *otr_arr, int n);
void mergeSort (otr* start, otr* finish, otr* buffer);
void sliv (otr* arr1, otr* arr2, int sz1, int sz2, otr* buffer);

int main ()
    {
    int n = 0;
    int m = 0;
    scanf ("%d %d", &n, &m);

    otr *otr_arr = new otr[2*n];
    Scan_otr (otr_arr, n);

    otr *point = new otr[m];
    for (int i = 0; i < m; i++)
        {
        scanf ("%d", &point[i].p);
        point[i].flag_l = 0;
        point[i].num = i;
        }

    otr *buffer = new otr[2*n];
    mergeSort (otr_arr, otr_arr + 2*n, buffer);
    mergeSort (point  , point   +   m, buffer);


    for (int i = 0, j = 0, summ = 0; i < 2*n && j < m; i++)
        {
        if (point[j].p < otr_arr[i].p)
            for (; point[j].p <= otr_arr[i].p; j++)
                point[j].flag_l = summ;
        summ += otr_arr[i].flag_l;
        }

    for (int i = 0; i < m; i++)
        {
        point[i].p = point[i].num;
        }

    mergeSort (point  , point   +   n, buffer);

    for (int i = 0; i < m; i++)
        printf ("%d ", point[i].flag_l);

    delete []point;
    delete []otr_arr;
    delete []buffer;

    return 0;
    }

void Scan_otr (otr *otr_arr, int n)
    {
    int t1 = 0;
    int t2 = 0;
    for (int i = 0; i < n; i++)
        {
        scanf ("%d %d", &t1, &t2);

        otr_arr[2*i    ].p = t1;
        otr_arr[2*i + 1].p = t2;
        if (t1 < t2)
            {
            otr_arr[2*i  ].flag_l =  1;
            otr_arr[2*i+1].flag_l = -1;
            }
        else
            {
            otr_arr[2*i  ].flag_l = -1;
            otr_arr[2*i+1].flag_l =  1;
            }
        }

    }

void mergeSort (otr* start, otr* finish, otr* buffer)
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

void sliv (otr* arr1, otr* arr2, int sz1, int sz2, otr* buffer)
    {
    int i = 0;
    int j = 0;

    for (;i + j < sz1 + sz2;)
        {
        if (i >= sz1)
            {
            for (;j < sz2; j++)
                {
                buffer [i + j].p      = arr2[j].p;
                buffer [i + j].flag_l = arr2[j].flag_l;
                buffer [i + j].num    = arr2[j].num;
                }
            break;
            }
        if (j >= sz2)
            {
            for (;i < sz1; i++)
                {
                buffer [i + j].p      = arr1[i].p;
                buffer [i + j].flag_l = arr1[i].flag_l;
                buffer [i + j].num    = arr1[i].num;
                }
            break;
            }

        if (arr1[i].p > arr2[j].p)
            {
            buffer [i + j].p      = arr2[j].p;
            buffer [i + j].flag_l = arr2[j].flag_l;
            buffer [i + j].num    = arr2[j].num;
            j++;
            }
        else
            {
            buffer [i + j].p      = arr1[i].p;
            buffer [i + j].flag_l = arr1[i].flag_l;
            buffer [i + j].num    = arr1[i].num;
            i++;
            }
        }

    for (int k = 0; k < sz1; k++)
        {
        arr1[k].p      = buffer[k].p;
        arr1[k].flag_l = buffer[k].flag_l;
        arr1[k].num    = buffer[k].num;
        }
    for (int k = 0; k < sz2; k++)
        {
        arr2[k].p      = buffer[k + sz1].p;
        arr2[k].flag_l = buffer[k + sz1].flag_l;
        arr2[k].num = buffer[k + sz1].num;
        }
    }
