#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void functionDFS(vector<vector<int>>& nodes, int V, vector<bool>& visits)
{
	if (visits[V]) return;

	printf("%d ", V);
	visits[V] = true;

	for (int i = 0; i < nodes[V].size(); i++)
	{
		functionDFS(nodes, nodes[V][i], visits);
	}
}

void functionBFS(vector<vector<int>>& nodes, int V, vector<bool>& visits)
{
	queue<int> bfsQue;

	bfsQue.push(V);
	visits[V] = true;

	while (!bfsQue.empty())
	{
		V = bfsQue.front();
		bfsQue.pop();

		printf("%d ", V);

		for (int i = 0; i < nodes[V].size(); i++)
		{
			if (visits[nodes[V][i]]) continue;

			bfsQue.push(nodes[V][i]);
			visits[nodes[V][i]] = true;
		}
	}
}

int main()
{
	vector<vector<int>> nodes;
	vector<bool> visits;

	int n = 0, m = 0, V = 0;

	cin >> n >> m >> V;

	nodes.resize(n + 1);
	visits.resize(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		vector<int> temp;
		int nodeA = 0, nodeB = 0;
		cin >> nodeA >> nodeB;
		nodes[nodeA].push_back(nodeB);
		nodes[nodeB].push_back(nodeA);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(nodes[i].begin(), nodes[i].end());
	}

	functionDFS(nodes, V, visits);
	fill(visits.begin(), visits.end(), false);
	printf("\n");
	functionBFS(nodes, V, visits);
	
	return 0;
}