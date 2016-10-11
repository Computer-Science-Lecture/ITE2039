//2015004584_Baejiun_A
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int A, B, k;
int main(int argc, char * argv[])
{
   int N, M, K; 
   scanf("%d %d %d", &N, &M, &K);
   int * s = (int*)calloc(++M, sizeof(int));
   vector< pair<int, int> > q;

   while (K--) {
      scanf("%d %d", &A, &B);
      q.push_back(make_pair(A, B));
   }

   while (N--) {
      int temp = scanf("%d", &k);
      s[k] += temp;
   }

   s[0] = 0;
   for (int i = 1; i <= M; ++i)
      s[i] += s[i - 1];
   
   for (int i = 0; i < (int)q.size(); ++i)
      printf("%d\n", s[q[i].second] - s[--q[i].first]);

   return 0;
}