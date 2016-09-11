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

void process(__container__ v)
{
  int i, j, k;
  i = n-1;
  while ( i-- > 0 )  
  {
    k = v[(j=i)];
    while ( ++j < n && k > v[j] );

    if ( --j == i ) continue;
    memcpy ( v+i, v+i+1, sizeof(*v) * (j-i) );
    v[j] = k;
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