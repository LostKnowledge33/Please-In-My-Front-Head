#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

int main()
{
	vector<vector<int>> cities;

	int n = 0, m = 0;

	cin >> n >> m;

	cities.reserve(n + 1);
	cities.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cities[i] = vector<int>(n + 1, INF);
	}
		
	for (int i = 0; i < m; i++)
	{
		int a = 0, b = 0, c = 0;

		cin >> a >> b >> c;
		if (cities[a][b] != INF)
			cities[a][b] = min(cities[a][b], c);
		else
			cities[a][b] = c;
	}

	for (int i = 1; i <= n; i++)
	{
		cities[i][i] = 0;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cities[i][j] = min(cities[i][j], cities[i][k] + cities[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (cities[i][j] == INF) cout << 0 << " ";
			else cout << cities[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}