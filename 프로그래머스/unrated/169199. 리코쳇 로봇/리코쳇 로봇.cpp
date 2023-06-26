#include <string>
#include <vector>
#include <queue>

using namespace std;

#define INT_MAX       2147483647

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int solution(vector<string> board) {
    
    vector<vector<int>> visit(100, vector<int>(100, INT_MAX));
    
    int x = 0, y = 0;
    for(int i = 0; i < board.size(); i++)
    {
        if(board[i].find("R") != string::npos)
        {
            x = i;
            y = board[i].find("R");
            visit[x][y] = 0;
            break;
        }
    }
    
    queue<pair<int, int>> Q;
    Q.push(make_pair(x, y));
    
    while(!Q.empty())
    {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int ix = x, iy = y;
            while(true)
            {
                ix += dx[i];
                iy += dy[i];
                if(ix >= board.size() || ix < 0 || iy >= board[0].length() || iy < 0) break;
                if(board[ix][iy] == 'D') break;
            }
            ix -= dx[i];
            iy -= dy[i];
            
            if(visit[ix][iy] != INT_MAX) continue;
            visit[ix][iy] = min(visit[ix][iy], visit[x][y] + 1);
            Q.push(make_pair(ix, iy));
        }
    }
    
    for(int i = 0; i < board.size(); i++)
    {
        if(board[i].find("G") != string::npos)
            return visit[i][board[i].find("G")] != INT_MAX ? visit[i][board[i].find("G")] : -1;
    }
    
    
}