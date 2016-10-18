// 2015004584_배지운_A
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(int argc, char * argv[]) 
{
    int count, e1, e2, ex1, ex2;
    int *a1, *a2, *t1, *t2, *r1, *r2, *route, *result;

    scanf("%d", &count);

    a1 = (int*)malloc(count * sizeof(int));
    a2 = (int*)malloc(count * sizeof(int));
    t1 = (int*)malloc(count * sizeof(int));
    t2 = (int*)malloc(count * sizeof(int));
    r1 = (int*)malloc(count * sizeof(int));
    r2 = (int*)malloc(count * sizeof(int));
    result = (int*)malloc(count * sizeof(int));

    scanf("%d %d", &e1, &e2);
    scanf("%d %d", &ex1, &ex2);


    for (int i = 0; i < count; ++i) {
        scanf("%d", a1+i);
    }
    for (int i = 0; i < count; ++i) {
        scanf("%d", a2+i);
    }
    for (int i = 0; i < count-1; ++i) {
        scanf("%d", t1+i);
    }
    for (int i = 0; i < count-1; ++i) {
        scanf("%d", t2+i);
    }

    int result1[count], result2[count];
    result1[0] = e1 + a1[0];
    result2[0] = e2 + a2[0];

    result[0] = (result1[0] <= result2[0]) + 1;

    for(int i = 1; i < count; ++i) 
    {
        result1[i] = min(result1[i-1] + a1[i], result2[i-1] + t2[i-1] + a1[i]);
        result2[i] = min(result2[i-1] + a2[i], result1[i-1] + t1[i-1] + a2[i]);

        r1[i] = ((result1[i-1] + a1[i] > result2[i-1] + t2[i-1] + a1[i]) + 1);
        r2[i] = ((result2[i-1] + a2[i] <= result1[i-1] + t1[i-1] + a2[i]) + 1);
    }

    int res1 = result1[count-1] + ex1, res2 = result2[count-1] + ex2;

    // Set last edge to find reverse order
    if (res1 <= res2) 
    {
        route = r1;
        result[count-1] = 1;
    } else 
    {
        route = r2;
        result[count-1] = 2;
    }

    printf("%d\n", min(res1, res2));

    for (int i = count-1; i > 0; --i) 
    {
        result[i-1] = route[i];
        if (route[i] == 2) {
            route = r2;
        } else if (route[i] == 1) {
            route = r1;
        }
    }
    for(int i=0; i < count; ++i) 
        printf("%d %d \n", result[i], i+1);

    free(a1);
    free(a2);
    free(t1);
    free(t2);
    free(r1);
    free(r2);
    free(result);

    return 0;
}
