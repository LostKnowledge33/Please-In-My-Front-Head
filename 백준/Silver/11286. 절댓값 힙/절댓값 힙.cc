#include <iostream>
#include <queue>
using namespace std;

struct cmp
{
	bool operator()(int& a, int& b)
	{
		if (abs(a) > abs(b))
		{
			return true;
		}
		else if (abs(a) == abs(b))
		{
			if (a > b) return true;
			else return false;
		}
		else
			return false;
	}
};

int main()
{
	priority_queue<int, vector<int>, cmp> absQue;

	int N = 0, input = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> input;

		if (input)
		{
			absQue.push(input);
		}
		else
		{
			if (absQue.empty())
				cout << 0 << "\n";
			else
			{
				cout << absQue.top() << "\n";
				absQue.pop();
			}	
		}
	}

	return 0;
}