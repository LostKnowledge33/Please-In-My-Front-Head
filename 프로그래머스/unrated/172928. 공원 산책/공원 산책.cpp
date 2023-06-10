#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    unordered_map<char, int> m;
    m['N'] = 0; m['S'] = 1; m['W'] = 2; m['E'] = 3;
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    int start[2] = { -1, -1 };
    
    for(int i = 0; i < park.size(); i++)
    {
        for(int j = 0; j < park[i].length(); j++)
        {
            if(park[i][j] == 'S')
            {
                start[0] = i; start[1] = j;
                break;
            }
        }
        if(start[0] != -1)
            break;
    }
    
    for(int i = 0; i < routes.size(); i++)
    {
        bool canMove = true;
        char op = routes[i][0];
        int move = atoi(&routes[i][2]);
        int dir[2] = { start[0] + (dx[m[op]] * move), start[1] + (dy[m[op]] * move) };
        if( dir[0] < 0 || dir[1] < 0 || dir[0] >= park.size() || dir[1] >= park[0].length()) continue;
        
        for(int j = 1; j <= move; j++)
        {
            dir[0] = dx[m[op]] * j; dir[1] = dy[m[op]] * j;
            if(park[start[0] + dir[0]][start[1] + dir[1]] == 'X') 
            {
                canMove = false;
                break;
            }
        }
        if(canMove)
        {
            start[0] += dir[0];
            start[1] += dir[1];
        }
    }
    
    answer.push_back(start[0]);
    answer.push_back(start[1]);
    
    return answer;
}