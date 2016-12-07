#include <stdio.h>
#include <vector>

#pragma warning (disable : 4996)
using namespace std;

int main(int argc, char * argv[])
{
	int n; scanf("%d", &n);
	vector<int> p(n + 1), r(n + 1, 0), s(n + 1, 0);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);

	for (int i = 1; i <= n; ++i)
	{
		int q = -1;
		for (int j = 1; j <= i; ++j)
			if (q < p[j] + r[i - j])
			{
				q = p[j] + r[i - j];
				s[i] = j;
			}
		r[i] = q;
	}

	printf("%d\n", r[n]);
	while (n > 0)
	{
		printf("%d ", s[n]);
		n -= s[n];
	}

	return 0;
}