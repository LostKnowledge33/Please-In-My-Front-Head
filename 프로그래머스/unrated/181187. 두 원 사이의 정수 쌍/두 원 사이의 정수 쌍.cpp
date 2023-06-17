#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for (int i = 1; i < r2; ++i) 
    {
        int out = 0, in = 0;

        out = (int)floor(sqrt(pow(r2, 2) - pow(i, 2)));
        
        if(i < r1)
            in = (int)ceil(sqrt(pow(r1, 2) - pow(i, 2)));
        else 
            in = 1;
              
        answer += (out - in + 1);
    }

    return 4 * (answer + r2 - r1 + 1);
}