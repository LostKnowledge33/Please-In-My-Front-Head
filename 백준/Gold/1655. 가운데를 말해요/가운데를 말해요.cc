#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
    
	priority_queue<int, vector<int>, less<int>> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;

	int N = 0;
	int number = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> number;
		if (maxheap.empty())
			maxheap.push(number);
		else if (maxheap.size() == minheap.size())
			maxheap.push(number);
		else
			minheap.push(number);

		if (!minheap.empty() && !maxheap.empty())
		{
			if (maxheap.top() > minheap.top())
			{
				int max = maxheap.top();
				int min = minheap.top();

				maxheap.pop();
				minheap.pop();

				maxheap.push(min);
				minheap.push(max);
			}
		}

		cout << maxheap.top() << '\n';
	}

	return 0;
}