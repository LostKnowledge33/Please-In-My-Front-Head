#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tall = 0, sum = 0;
	vector<int> talls;

	for(int i = 0; i < 9; i++)
    {
        cin >> tall;
		talls.push_back(tall);
		sum += tall;
	}

	sort(talls.begin(), talls.end());

	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			if (sum - (talls[i] + talls[j]) == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j) continue;
					cout << talls[k] << endl;
				}
				return 0;
			}
		}
	}
	
	return 0;
}