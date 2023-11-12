#include <iostream>

using namespace std;

int main()
{
	int N = 0, pos = 1, i = 1;

	cin >> N;

	while (true)
	{
		if (pos >= N)
			break;

		pos += i * 6;
		i++;
	}

	cout << i << "\n";

	return 0;
}