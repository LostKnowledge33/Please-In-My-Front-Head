#include <iostream>

using namespace std;

int main()
{

	int	liontable[100001] = { 0, };

	int N = 0;

	cin >> N;

	liontable[0] = 1;
	liontable[1] = 3;

	for (int i = 2; i <= N; i++)
	{
		liontable[i] = ((liontable[i - 1] * 2) + liontable[i - 2]) % 9901;
 	}

	cout << liontable[N]  << "\n";

	return 0;
}