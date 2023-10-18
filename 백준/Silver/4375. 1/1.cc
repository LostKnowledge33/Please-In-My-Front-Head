#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	while(cin >> n)
    {
        int mod = 1, count = 0;
        while (true)
        {
            count++;

            if ((mod % n) == 0)
            {
                cout << count << endl;
                break;
            }
            else
            {
                mod %= n;
                mod = (mod * 10 + 1);
            }
        }  
    }
	
	return 0;
}