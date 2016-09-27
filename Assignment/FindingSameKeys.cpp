#include <stdio.h>
#include <vector>
using namespace std;
int n, k, m = 0, t;
int main()
{
    scanf("%d %d", &n, &k);
    vector<bool> v(100001, false);
    while(--n + 1)
    {
        scanf("%d", &t);
        v[t] = true;
    }
    while(--k + 1)
    {
        scanf("%d", &t);
        if (v[t])
        {
            ++m;
            v[t] = false;
        }
    }
    printf("%d\n", m);
    return 0;
}