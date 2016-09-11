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
int m;
int main()
{
	scanf("%d", &n);
    scanf("%d", &m);
	__container__ v = (__container__)malloc(sizeof(__type__) * n);
	input(v, n);
	process(v);
	print(v);
	free(v);
	return 0;
}

void process(__container__ v)
{
    int i, j, k;

    for (i = 0; i < m; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
            if (v[j] < v[k])
                k = j;

        if (v[k] != v[i])
            v[k] ^= v[i] ^= v[k] ^= v[i];
    }
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