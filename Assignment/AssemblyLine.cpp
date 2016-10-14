//2015004584_Baejiun_A
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(int argc, char * argv[])
{
	int temp;
	int N;
	pair<int, int> e, x;
	pair< vector<int>, vector<int> > a, t;
	pair< vector<bool>, vector<bool> > r;

	// input
	scanf("%d", &N);
	scanf("%d %d %d %d", &e.first, &e.second, &x.first, &x.second);

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
		r.first.push_back(temp == a.second[i - 1] + t.second[i - 1]);

		temp = min(a.first[i - 1] + t.first[i - 1], a.second[i - 1]);
		a.second[i] += temp;
		r.second.push_back(temp == a.second[i - 1]);
	}

	// print
	stack<int> result;
	temp = min(a.first[N - 1] + x.first, a.second[N - 1] + x.second);
	printf("%d\n", temp);
	bool rec = (temp == a.second[N - 1] + x.second);
	result.push(rec ? 2 : 1);

	for (int i = r.first.size() - 1; i + 1; --i)
	{
		if (!rec) {
			result.push(r.first[i] ? 2 : 1);
			rec = (r.first[i]);
		}
		else {
			result.push(r.second[i] ? 2 : 1);
			rec = (r.second[i]);
		}
	}

	for (int i = 0; i <= (int)r.first.size(); ++i)
	{
		printf("%d %d\n", result.top(), i + 1);
		result.pop();
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