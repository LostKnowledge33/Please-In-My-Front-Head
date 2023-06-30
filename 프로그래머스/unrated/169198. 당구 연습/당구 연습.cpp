#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    int cnt = balls.size();
    
    for(int i = 0; i < cnt; i++)
    {
        int len, x, y;
        if (balls[i][0] == startX)
        {
            x = 2 * min(m - startX, startX);
            y = abs(startY - balls[i][1]);
            if (startY > balls[i][1]) len = pow(y + 2 * (n - startY), 2);
            else len = pow(y + 2 * startY, 2);
        }
        else if(balls[i][1] == startY)
        {
            x = abs(startX - balls[i][0]);
            y = 2 * min(n - startY, startY);
            if (startX > balls[i][0]) len = pow(x + 2 * (m - startX), 2);
            else len = pow(x + 2 * startX, 2);
        }
        else
        {
            x = min(startX + balls[i][0], 2 * m - startX - balls[i][0]);
            y = abs(startY - balls[i][1]);
            len = pow(x, 2) + pow(y, 2);
            x = abs(startX - balls[i][0]);
            y = min(startY + balls[i][1], 2 * n - startY - balls[i][1]);
        }
        
        len = min(len, (int)(pow(x, 2) + pow(y, 2)));
        answer.push_back(len);
    }
    
    return answer;
}