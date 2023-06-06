#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, w, L, t, count = 0, Qsize = 0;
    queue<int> Q;
    
    cin >> n >> w >> L;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        while (true)
        {
            if (Q.size() == w)
            {
                Qsize -= Q.front();
                Q.pop();
            }

            if (Qsize + t <= L) break;
            
            count++;
            Q.push(0);   
        }

        Qsize += t;
        Q.push(t);
        count++;
    }

    cout << count + w << endl;
    return 0;
}