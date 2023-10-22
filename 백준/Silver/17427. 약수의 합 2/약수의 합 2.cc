#include <iostream>

using namespace std;

int main()
{
	long long N, answer = 0;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		answer += (N / i) * i;
	}

	cout << answer;

	return 0;
}