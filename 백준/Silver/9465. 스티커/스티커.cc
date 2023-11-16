#include <iostream>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);

	int scoretable[2][100001] = { 0, };
	int sticker[2][100001] = { { 0, }, };

	int T = 0, N = 0;

	cin >> T;

	while (T)
	{
		cin >> N;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> sticker[i][j];
			}
		}

		scoretable[0][0] = 0;
		scoretable[1][0] = 0;
		scoretable[0][1] = sticker[0][0];
		scoretable[1][1] = sticker[1][0];

		for (int i = 2; i <= N; i++)
		{
			scoretable[0][i] = max(scoretable[1][i - 1], scoretable[1][i - 2]) + sticker[0][i - 1];
			scoretable[1][i] = max(scoretable[0][i - 1], scoretable[0][i - 2]) + sticker[1][i - 1];
		}

		cout << max(scoretable[0][N], scoretable[1][N]) << "\n";
		T--;
	}

	return 0;
}