//2015004584_Baejiun_A
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(int argc, char * argv[])
{
   int temp;
   int N; scanf("%d", &N);
   pair<int ,int> e, x;
   scanf("%d %d %d %d", &e.first, &e.second, &x.first, &x.second);

   pair< vector<int>, vector<int> > a, t, r;

   for (int i = 0; i < N; ++i)
   {
      scanf("%d", &temp);
      a.first.push_back(temp);
   }
   for (int i = 0; i < N; ++i)
   {
      scanf("%d", &temp);
      a.second.push_back(temp);
   }
   for (int i = 0; i < N - 1; ++i)
   {
      scanf("%d", &temp);
      t.first.push_back(temp);
   }
   for (int i = 0; i < N - 1; ++i)
   {
      scanf("%d", &temp);
      t.second.push_back(temp);
   }

   // init
   a.first[0] += e.first;
   a.second[0] += e.second;

   // process
   for (int i = 1; i < N; ++i)
   {
      temp = min(a.second[i - 1] + t.second[i - 1], a.first[i - 1]);
      a.first[i] += temp;
      r.first.push_back(temp);
      temp = min(a.first[i - 1] + t.first[i - 1], a.second[i - 1]);
      a.second[i] += temp;
      r.second.push_back(temp);
   }

   // print
   printf("%d\n", min(a.first[N - 1] + x.first, a.second[N - 1] + x.second));
   for(int i = 0; i < (int)r.first.size(); ++i)
   {
      printf("%d %d\n", r.first[i], r.second[i]);
   }

   return 0;
}

/*
6
2 4
3 2
7 9 3 4 8 4
8 5 6 4 5 7
2 3 1 3 4
2 1 2 2 1
*/