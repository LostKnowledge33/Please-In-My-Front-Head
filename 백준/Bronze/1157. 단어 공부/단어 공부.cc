#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<char, int> map;
	
	string word;
	cin >> word;

	for (int i = 0; i < word.length(); i++)
	{
		map[toupper(word[i])]++;
	}

	int max = 0, same = 0;
	char ch;

	for (auto data : map)
	{
		if (data.second == max)
		{
			same = data.second;
		}
		else if (data.second > max)
		{
			max = data.second;
			ch = data.first;
		}
	}

	if (max == same) cout << "?" << endl;
	else cout << ch << endl;

	return 0;
}
