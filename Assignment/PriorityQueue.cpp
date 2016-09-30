//2015004584_배지운_A
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

#define __type__ int
#define __container__ vector<int>
#define NIL -987654321

int input(void);
void input(__container__, int);
void process(__container__&);

int idx = 0;
vector<int> ext;
void swap(int * first, int * second)
{
    int x = *first;
    *first = *second;
    *second = x;
}

int main()
{
    __container__ v(1, 1987654321);
    process(v);
    return 0;
}

void process_(__container__& v, int i)
{
    if (i <= 0)
        return;
    
    if (v[i] > v[i/2])
    {
        swap(v[i], v[i/2]);
        process_(v, i/2);
    }
}

void process__(__container__& v, int i)
{
    if (i * 2 >= (int)v.size())
        return;
    
    int n;
    if (i * 2 == v.size()-1)
        n = i * 2;
    else
        n = v[i * 2] > v[i * 2 + 1] ? i * 2 : i * 2 + 1;
    


    if (v[i] < v[n])
    {
        swap(v[i], v[n]);
        process__(v, n);
    }
}
void process(__container__& v)
{
    for (;;)
    {
        int a = input();
        switch (a)
        {
            case 0:
                for (int i = 0; i < (int)ext.size(); ++i)
                    printf("%d ", ext[i]);
                printf("\n");
                for (int i = 1; i < (int)v.size(); ++i)
                    printf("%d ", v[i]);
                printf("\n");
                return;
                
            case 1:
            {
                int d = input();
                v.push_back(d);
                process_(v, (int)v.size() - 1);
                break;
            }
            case 2:
            {
                ext.push_back(v[1]);
                v[1] = v.back();
                v.pop_back();
                process__(v, 1);
                
                break;
            }
            case 3:
            {
                int x = input(), y = input();
                v[x] = y;
                
                if (v[x] > v[x/2])
                    process_(v, x);
                else
                    process__(v, x);
                
                break;   
            }
        }
    }
}

int input()
{
    int t; scanf("%d", &t);
    return t;
}
void input(__container__ container, int size)
{
    for(int i = 0; i < size; ++i)
        scanf("%d", &container[i]);
}