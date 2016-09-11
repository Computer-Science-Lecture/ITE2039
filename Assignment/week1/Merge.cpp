#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __type__ int
#define __container__ int*

void input(__container__, int);
void printr(__container__);
void print(__container__);
void process(__container__);

int n;
int main()
{
	scanf("%d", &n);
	__container__ v = (__container__)malloc(sizeof(__type__) * n);
	input(v, n);
	process(v);
	printr(v);
	free(v);
	return 0;
}

void _process_util(__container__ v, int l, int m, int r)
{
	int i, j, k, n1 = m - l + 1, n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; ++i)
        L[i] = v[l + i];

    for (j = 0; j < n2; ++j)
        R[j] = v[m + 1+ j];
 
    i = 0; j = 0; k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            v[k] = L[i++];
        else
            v[k] = R[j++];
        k++;
    }
 
    while (i < n1)
    {
        v[k] = L[i];
        i++; k++;
    }
 
    while (j < n2)
    {
        v[k] = R[j];
        j++; k++;
    }
}
void _process(__container__ v, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
        _process(v, l, m);
        _process(v, m + 1, r);
        _process_util(v, l, m, r);
	}
}
void process(__container__ v)
{
	_process(v, 0, n-1);
}

void input(__container__ container, int size)
{
	for(int i = 0; i < size; ++i)
	{
		int t; scanf("%d", &t);
		container[i] = t;
	}
}
void printr(__container__ container)
{
	for(int i = n - 1; i >= 0; --i)
		printf("%d\n", container[i]);
}
void print(__container__ container)
{
	for(int i = 0; i < n; ++i)
		printf("%d\n", container[i]);
}