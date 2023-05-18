#include <string>
#include <iostream>
using namespace std;

int main()
{
    string word;
	cin >> word;

	int len = word.length();

	if (len == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	for (int i = 0; i < len; i++)
	{
		if (word[i] != word[len - 1 - i])
		{
			cout << 0 << endl;
			return 0;
		}
		else if ((len - 1) - i < 2)
		{
			cout << 1 << endl;
			return 0;
		}
	}
    return 0;
}