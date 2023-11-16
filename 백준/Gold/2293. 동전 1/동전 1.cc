#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int cointable[10001] = { 0, };
	vector<int> coins;
	int n = 0, k = 0;

	cin >> n >> k;

	coins.reserve(n);

	for (int i = 0; i < n; i++)
	{
		int input = 0;
		cin >> input;

		coins.push_back(input);
	}

	cointable[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = coins[i]; j <= k; j++)
		{
			cointable[j] = cointable[j] + cointable[j - coins[i]];
		}
	}

	cout << cointable[k];
	
	return 0;
}