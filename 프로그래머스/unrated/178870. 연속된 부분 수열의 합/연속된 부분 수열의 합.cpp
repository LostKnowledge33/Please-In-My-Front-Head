#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 2147483647};
    
    int start = 0, end = 0, sum = sequence[0];
    while(start <= end && end < sequence.size())
    {
        if(sum > k)
            sum -= sequence[start++];
        else if(sum == k)
        {
            if(answer[1] - answer[0] > end - start)
            {
                answer[0] = start;
                answer[1] = end;
            }
            sum -= sequence[start++];
        }
        else
            sum += sequence[++end];
    
    }
    
    return answer;
}