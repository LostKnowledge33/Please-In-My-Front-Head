#include <iostream>

using namespace std;

long long divisorTable[1000000] = { 0, };

int main()
{
    cin.tie(NULL);
    
	int N = 0, T = 0, answer = 0;
	
	for (int i = 1; i <= 1000000; i++)
	{
		for (int j = 1; i * j <= 1000000; j++)
		{
			divisorTable[i * j] += i;
		}
		divisorTable[i] += divisorTable[i - 1];
	}

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << divisorTable[N] << "\n";
	}

	return 0;
}