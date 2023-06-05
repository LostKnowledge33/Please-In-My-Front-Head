#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int del = 0, count = 0;

    while (true)
    {
        int size = 0;
        for (char c : s)
            if (c == '1') size++;

        del += s.length() - size;

        bitset<150000> bs(size);

        s = bs.to_string();
        s = s.substr(s.find('1'));
        count++;

        if (s == "1")
        {
            answer.emplace_back(count);
            answer.emplace_back(del);
            break;
        }
    }
    
    return answer;
}