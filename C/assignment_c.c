#include <stdio.h>
#define N 1000010

int q[N], n;
void quicksort(int l, int r)
{
    if (l >= r) return;
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        int mid = i + r >> 1;
        while (q[++ i] < mid);
        while (q[-- j] > mid);
        if (i < j) swap(q[i], q[j]);
    }

}
