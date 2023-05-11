#include <iostream>
using namespace std;

int main()
{
   	int batch = 0;
	cin >> batch;

	for (int i = 0; i < batch; i++)
	{
        int N = 0, M = 0;
		cin >> N >> M;

		long long answer = 1;
		int r = 1;
        
		for(int j = M; j > M - N; j--)
		{ 
			answer *= j;
			answer /= r++;
		}
		cout << answer << endl;
	}
    
    return 0;
}