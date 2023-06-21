#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0, sum = 0;
    int ea = (picks[0] + picks[1] + picks[2]) * 5;

    vector<int> use(ea / 5);
    vector<pair<int, int>> sums;
    
    for(int i = 0; i < ea; i++)
    {
        if(i == minerals.size()) 
        {
            sums.push_back(make_pair(sum, i - i % 5));
            break;
        }
        
        if(minerals[i] == "diamond") sum += 25;
        else if(minerals[i] == "iron") sum += 5;
        else sum += 1;
        
        if(!((i + 1) % 5)) 
        {
            sums.push_back(make_pair(sum, i - 4));
            sum = 0;
        }
    }
    
    sort(sums.begin(), sums.end(), greater<pair<int, int>>());

    for(auto data : sums)
    {
        for(int i = 0; i < picks.size(); i++)
        {
            if(picks[i]) 
            {
                use[data.second / 5] = i;
                picks[i]--;
                break;
            }
        }
    }
    
    for(int i = 0; i < ea; i++)
    {
        if(i == minerals.size()) break;
        switch(use[i / 5])
        {
            case 0:
                answer += 1;
                break;
            case 1:
                if(minerals[i] == "diamond") answer += 5;
                else answer += 1;
                break;
            case 2:
                if(minerals[i] == "diamond") answer += 25;
                else if(minerals[i] == "iron") answer += 5;
                else answer += 1;
                break;
        }
    }
    
    return answer;
}