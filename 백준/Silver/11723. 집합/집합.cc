#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int M, x, S = 0;
	int all = 0xFFFFFF;

	string oper;
	
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> oper;
        
        if (oper == "all")
		{
			S |= all;
            continue;
		}
		else if (oper == "empty")
		{
			S &= 0;
            continue;
		}
        
        cin >> x;

		if (oper == "add")
		{
			S |= 1 << x;
		}
		else if (oper == "remove")
		{
			S &= ~(1 << x);
		}
		else if (oper == "check")
		{
			if (S & 1 << x) cout << "1\n";
			else cout << "0\n";
		}
		else if (oper == "toggle")
		{
			S ^= 1 << x;
		}
	}
	
	return 0;
}