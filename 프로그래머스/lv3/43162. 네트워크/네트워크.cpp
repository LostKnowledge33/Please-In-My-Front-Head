#include <string>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& v, int n)
{
    if(!v[n][n]) return false;
    
    v[n][n] = 0;
    
    for(int i = 0; i < v.size(); i++)
        if(v[n][i]) dfs(v, i);

    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(computers[i][i] && dfs(computers, i)) answer++;
    }
    
    return answer;
}