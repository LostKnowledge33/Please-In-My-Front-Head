#include<vector>
#include<queue>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int solution(vector<vector<int> > maps)
{
    int m, n;
    m = maps.size(); n = maps[0].size();
    vector<vector<int>> visit(m, vector<int>(n, 0));
    
    queue<pair<int, int>> Q;
    
    Q.push({0, 0});
    visit[0][0] = 1;
    
    while(!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if( nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if( !maps[nx][ny] || visit[nx][ny] ) continue;
            
            visit[nx][ny] = 1;
            maps[nx][ny] = maps[x][y] + 1;
            Q.push({nx, ny});
        }
    }
    
    if(maps[m - 1][n - 1] == 1) return -1;
    return maps[m - 1][n - 1];
}