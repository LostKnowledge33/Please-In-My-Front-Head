#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int stats[20][20];
vector<bool> teams;
int N = 0, lteam = 0, rteam = 0, answer = INT_MAX;

void Calc()
{
    vector<int> start; // 스타트 팀원의 인덱스값
    vector<int> link; // 링크팀 팀원의 인덱스값
    int start_score = 0;
    int link_score = 0;
    for(int i = 0; i < N; i++)
    {
        if(teams[i] == true) // 선택된 사람들은 start팀에
            start.push_back(i);
        else // 그 외의 사람들은 link팀으로
            link.push_back(i);
    }
    for(int i = 0; i < (N/2); i++)
        for(int j = 0; j < (N/2); j++)
        {
            start_score += stats[start[i]][start[j]];
            link_score += stats[link[i]][link[j]];
        } // 각 팀의 능력치의 합 계산

	if (abs(start_score - link_score) <= answer) answer = abs(start_score - link_score);
}

void DFS(int current, int index)
{
	if (current == (N / 2))
	{
		Calc();
		return;
	}
		
	for (int i = index; i < N; i++)
	{
		teams[i] = true;
		DFS(current + 1, i + 1);
		teams[i] = false;
	}
	
}

int main()
{
    cin >> N;
	teams.resize(N);

	for (int i = 0; i < N; i++)
	{
        for (int j = 0; j < N; j++)
	    {
		    cin >> stats[i][j];
        }
	}

	DFS(0, 0);
    cout << answer << endl;
    
    return 0;
}