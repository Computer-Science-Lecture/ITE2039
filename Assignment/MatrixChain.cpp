#include <stdio.h>
#include <vector>

using namespace std;

#pragma warning (disable : 4996);
#define MAX 987654321

int process(const vector<int>& p, int n)
{
	vector< vector< int > > m(n, vector<int>(n, 0));

	for (int L = 2; L < n; L++)
	{
		for (int i = 1; i < n - L + 1; i++)
		{
			int j = i + L - 1, q;
			m[i][j] = MAX;
			for (int k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	return m[1][n - 1];
}

int main()
{
	int n;	scanf("%d", &n);
	vector<int> a(n + 1);
	
	for (int i = 0; i < n + 1; ++i)
		scanf("%d", &a[i]);

	int res = process(a, a.size());
	printf("%d\n", res);

	return 0;
}