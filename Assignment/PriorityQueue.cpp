#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __type__ int
#define __container__ int*

void input(__container__, int);
void printr(__container__);
void print(__container__);
void process(__container__);

int n, k;
void swap(int * first, int * second)
{
    if (*first - *second)
        *first ^= *second ^= *first ^= *second;
}
int main()
{
    scanf("%d %d", &n, &k);
    __container__ v = (__container__)malloc(sizeof(__type__) * n);
    input(v, n);
    process(v);

    for(int i = n - 1; i >= n-k; --i)
        printf("%d ", v[i]);
    printf("\n");
    for(int i = n - k - 1; i >= 0; --i)
        printf("%d ", v[i]);
    
    free(v);
    return 0;
}

void process_(__container__ v, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && v[l] > v[largest])
        largest = l;
 
    if (r < n && v[r] > v[largest])
        largest = r;
 
    if (largest != i)
    {
        swap(&v[i], &v[largest]);
        process_(v, n, largest);
    }
}
 
void process(__container__ v)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        process_(v, n, i);
 
    for (int i=n-1; i>=0; i--)
    {
        swap(&v[0], &v[i]);
        process_(v, i, 0);
    }
}

void input(__container__ container, int size)
{
    for(int i = 0; i < size; ++i)
        scanf("%d", &container[i]);
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