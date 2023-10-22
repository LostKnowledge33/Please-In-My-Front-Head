#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<int> vNums;

	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;

		vNums.push_back(data);
	}

	sort(vNums.begin(), vNums.end());

	if (vNums.size() == 1)
		cout << vNums[0] * vNums[0] << "\n";
	else
		cout << vNums[0] * vNums[vNums.size()-1] << "\n";

	return 0;
}