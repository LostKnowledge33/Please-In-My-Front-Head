#include <iostream>

using namespace std;

int main()
{
	int pieces[6] = { 1, 1, 2, 2, 2, 8 };
	
	for (int i = 0; i < 6; i++)
	{
		int input = 0;
		cin >> input;

		cout << pieces[i] - input << " ";
	}

	return 0;
}