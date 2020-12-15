#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<pair<int, int>>& a, vector<bool>& visited, int now)
{
	queue<int> q;
	printf("%d ", now);
	visited[now] = true;
	q.push(now);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = visited.size() - 1; i >= 0; --i)
		{
			if (a[x * visited.size() + i].second != 0 && visited[a[x * visited.size() + i].first] == false)
			{
				printf("%d ", a[x * visited.size() + i].first);
				visited[a[x * visited.size() + i].first] = true;
				q.push(a[x * visited.size() + i].first);
			}
		}
	}
}

void DFS(vector<pair<int,int>> &a,vector<bool> &visited,int now)
{
	printf("%d ", now);
	visited[now] = true;
	for (int i = visited.size() -1 ; i >=0 ; --i)
	{
		if (a[now * visited.size() + i].second != 0 && visited[a[now * visited.size() + i].first] == false)
		{
			DFS(a, visited, a[now * visited.size() + i].first);
		}
	}
}

void output_link(vector<pair<int, int>>& a, vector<bool>& visited)
{
	int size = visited.size();
	for (int i = 0; i < size; ++i)
	{
		printf("%3d: ", i);
		for (int j = size - 1; j >= 0; --j)
		{
			if (a[i * size + j].second != 0)
				printf("%3d[%d]¡ú", a[i * size + j].first, a[i * size + j].second);
			if (j == 0)
				break;
		}
		printf("\n");
	}
}

int main()
{
	unsigned int size = 0, n = 0, i = 0, j = 0;
	vector<pair<int, int> >* a = new vector<pair<int, int> >;
	vector<bool> visited;
	scanf("%u", &size);
	a->resize(size);
	for (i = 0; i < size * size; ++i)
	{
		a->push_back(make_pair(i / size, 0));
	}
	for (i = 0; i < size; ++i)
		visited.push_back(false);
	scanf("%u", &n);
	int x, y, z;
	for (i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &x, &y, &z);
		for (j = 0; j < size; ++j)
		{
			if ((*a)[x * size + j].second == 0)
			{
				(*a)[x * size + j] = make_pair(y, z);
				break;
			}
			else
				continue;
		}

	}
//	DFS(*a, visited,0);
//	printf("\n");
//	for (i = 0; i < size; ++i)
//		visited[i]=false;
//	BFS(*a, visited, 0);
//	printf("\n");
//	output_link(*a, visited);
//	printf("\n");
	return 0;
}
