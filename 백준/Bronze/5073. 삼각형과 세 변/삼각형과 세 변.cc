#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int lines[3];

	while (true)
	{
		int endcheck = 0, same = 0;
		for (int i = 0; i < 3; i++)
		{ 
			cin >> lines[i];
			endcheck += lines[i];
		}
			
		if (endcheck == 0) break;

		sort(lines, lines + 3);
		if (lines[2] >= (lines[1] + lines[0]))
		{ 
			cout << "Invalid\n";
			continue;
		}

		if (lines[0] == lines[1]) same++;
		if (lines[1] == lines[2]) same++;
		if (lines[0] == lines[2]) same++;

		switch (same)
		{
		case 0:
			cout << "Scalene\n";
			break;
		case 1:
			cout << "Isosceles\n";
			break;
		case 3:
			cout << "Equilateral\n";
			break;
		}
	}

	return 0;
}