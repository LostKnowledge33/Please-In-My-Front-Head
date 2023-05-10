#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	return a.second < b.second;
}

vector<string> solution(vector<string> players, vector<string> callings) 
{
   	unordered_map<string, int> player;
	unordered_map<int, string> ranking;
    vector<string> answer;

	for (int i = 0; i < players.size(); i++)
	{
		player[players[i]] = i;
		ranking[i] = players[i];
	}

	for (string call : callings)
	{
		int rank = player[call];

		swap(ranking[rank], ranking[rank - 1]);
		swap(player[ranking[rank]], player[ranking[rank - 1]]);
	}
	
	vector<pair<string, int>> vec(player.begin(), player.end());
	sort(vec.begin(), vec.end(), cmp);
    
    for (auto out : vec)
	{
		answer.push_back(out.first);
 	}

    return answer;
}