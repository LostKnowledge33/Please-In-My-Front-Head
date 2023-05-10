#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<char, int> mapChars;
    string st;
    
    cin >> st;

	for (int i = 0; i < 26; i++)
	{
		mapChars[(char)i + 97] = 0;
	}

	for (int i = 0; i < st.length(); i++)
	{
		mapChars[st[i]]++;
	}
	
	for (auto out : mapChars)
	{
		cout << out.second << " ";
	}
    
    return 0;
}
