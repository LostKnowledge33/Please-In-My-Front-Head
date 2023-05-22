#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    int n = citations.size();
    
    if(citations[0] >= n) return n;
    
    for(int h = n; h >= 0; h--)
    {
        for(int i = 0; i < n; i++)
        {
            if(citations[i] >= h && (n - i) >= h)
                return h;
        }
    }
    
    
    return answer;
}