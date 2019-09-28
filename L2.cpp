#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct otr
    {
    int p;
    int flag_l;
    int num;
    };

void Scan_otr (otr *otr_arr, int n);
void mergeSort (otr *start, otr *finish, otr *buffer, int *i, int *j, int *k);
void sliv (otr* arr1, otr* arr2, int sz1, int sz2, otr* buffer, int *i, int *j, int *k);

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

    int sz = 0;
    if (n > m) sz = 2*n;
    else sz = 2*m;
    otr *buffer = new otr[sz];

    int a = 0;
    int b = 0;
    int c = 0;
    mergeSort (otr_arr, otr_arr + 2*n, buffer, &a, &b, &c);
    mergeSort (point  , point   +   m, buffer, &a, &b, &c);

    int j = 0;
    int summ = 0;
    int summ2 = 0;
    int i0 = 0;
    for (; point[j].p < otr_arr[0].p && j < m; j++)
            {
            assert (j < m);
            point[j].flag_l = summ;
            }

    for (int i = 0; i < 2*n && j < m; i++)
        {
        summ2 = summ;
        i0 = i;
        assert (i < 2*n);
        if (otr_arr[i].flag_l > 0)
            summ += otr_arr[i].flag_l;

        assert (i < 2*n);
        for (; i < 2*n - 1 && otr_arr[i].p == otr_arr[i + 1].p; i++)
            {
            assert (i + 1 < 2*n);
            if (otr_arr[i + 1].flag_l > 0)
                summ += otr_arr[i + 1].flag_l;
            }

        if (i < 2*n)
            {
            assert (i < 2*n);
            assert (j < m);
            for (; point[j].p <= otr_arr[i].p && j < m; j++)
                {
                assert (j < m);
                assert (i < 2*n);
                if (point[j].p == otr_arr[i].p) point[j].flag_l = summ;
                else point[j].flag_l = summ2;
                }
            }

        if (i == 2*n - 1 && j < m)
            for (; point[j].p == otr_arr[i].p && j < m; j++)
                {
                assert (j < m);
                assert (i < 2*n);
                point[j].flag_l = summ;
                }

        i = i0;
        assert (i < 2*n);
        if (otr_arr[i].flag_l < 0)
            {
            assert (i < 2*n);
            summ += otr_arr[i].flag_l;
            }

        for (; i < 2*n - 1 && otr_arr[i].p == otr_arr[i + 1].p; i++)
            {
            assert (i + 1 < 2*n);
            if (otr_arr[i + 1].flag_l < 0)
                summ += otr_arr[i + 1].flag_l;
            }
        }

    for (int i = 0; i < m; i++)
        {
        assert (i < m);
        point[i].p = point[i].num;
        }

    mergeSort (point, point + m, buffer, &a, &b, &c);

    for (int i = 0; i < m; i++)
        {
        assert (i < m);
        printf ("%d ", point[i].flag_l);
        }

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

void mergeSort (otr* start, otr* finish, otr* buffer, int *i, int *j, int *k)
    {
    if ((int)(finish - start) > 1)
        {
        mergeSort (start, start + ((int)(finish - start) + 1)/2,         buffer, i, j, k);
        mergeSort (       start + ((int)(finish - start) + 1)/2, finish, buffer, i, j, k);
        sliv (start, start + ((int)(finish - start) + 1)/2, ((int)(finish - start) + 1)/2, ((int)(finish - start))/2, buffer, i, j, k);
        }
    }

void sliv (otr* arr1, otr* arr2, int sz1, int sz2, otr* buffer, int* i, int* j, int* k)
    {
    (*i) = 0;
    (*j) = 0;
    (*k) = 0;

    for (;(*i) + (*j) < sz1 + sz2;)
        {
        if ((*i) >= sz1)
            {
            for (;(*j) < sz2; (*j)++)
                {
                buffer [(*i) + (*j)].p      = arr2[(*j)].p;
                buffer [(*i) + (*j)].flag_l = arr2[(*j)].flag_l;
                buffer [(*i) + (*j)].num    = arr2[(*j)].num;
                }
            break;
            }
        if ((*j) >= sz2)
            {
            for (;(*i) < sz1; (*i)++)
                {
                buffer [(*i) + (*j)].p      = arr1[(*i)].p;
                buffer [(*i) + (*j)].flag_l = arr1[(*i)].flag_l;
                buffer [(*i) + (*j)].num    = arr1[(*i)].num;
                }
            break;
            }

        if (arr1[(*i)].p > arr2[(*j)].p)
            {
            buffer [(*i) + (*j)].p      = arr2[(*j)].p;
            buffer [(*i) + (*j)].flag_l = arr2[(*j)].flag_l;
            buffer [(*i) + (*j)].num    = arr2[(*j)].num;
            (*j)++;
            }
        else
            {
            buffer [(*i) + (*j)].p      = arr1[(*i)].p;
            buffer [(*i) + (*j)].flag_l = arr1[(*i)].flag_l;
            buffer [(*i) + (*j)].num    = arr1[(*i)].num;
            (*i)++;
            }
        }

    for ((*k) = 0; (*k) < sz1; (*k)++)
        {
        arr1[(*k)].p      = buffer[(*k)].p;
        arr1[(*k)].flag_l = buffer[(*k)].flag_l;
        arr1[(*k)].num    = buffer[(*k)].num;
        }
    for ((*k) = 0; (*k) < sz2; (*k)++)
        {
        arr2[(*k)].p      = buffer[(*k) + sz1].p;
        arr2[(*k)].flag_l = buffer[(*k) + sz1].flag_l;
        arr2[(*k)].num = buffer[(*k) + sz1].num;
        }
    }
