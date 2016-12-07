// 2015004584_배지운_A

#include <stdio.h>

// dijkstra from https://github.com/MaybeS/ICPC2016/tree/master/headers
#pragma once
#include <queue>
#include <vector>
#include <utility>
using namespace std;

//Dijkstra.h 18/34
//map[i][j]={x,y}--i:index,j:start,x:end,y:cost
//dist[i]=j--i:end,j:cost
template<typename t_index, typename t_cost>
void dijkstra(const vector<vector<pair<t_index, t_cost> > >& map, vector<t_cost>& dist, const size_t& start)
{
	priority_queue<pair<t_index, t_cost> > pq;
	pq.push({ start, 0 });
	while (pq.size())
	{
		pair<t_index, t_cost> now = pq.top();
		pq.pop();
		for (int i = 0; i < map[now.first].size(); i++)
		{
			t_index next_index = map[now.first][i].first;
			if (dist[next_index] > -now.second + map[now.first][i].second)
			{
				dist[next_index] = -now.second + map[now.first][i].second;
				pq.push({ next_index, -dist[next_index] });
			}
		}
	}
}

int main(int argc, char * argv[])
{
	int N, x, y, e, w; scanf("%d", &N);
	vector<vector<pair<int, int> > > v(N+1, vector<pair<int, int> >());
	vector<int> d(N+1, 987654321);

	while (N--) {
		scanf("%d %d", &x, &y);
		while (y--) {
			scanf("%d %d", &e, &w);
			v[x].push_back(make_pair(e, w));
		}
	}

	dijkstra(v, d, 1);

	y = 0;
	for (x = 2; x < (int)d.size(); ++x)
		if (y < d[x])
			y = d[x];
	
	printf("%d\n", y);

	return 0;
}