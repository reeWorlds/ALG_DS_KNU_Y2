#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    deque<long long> q, min_q;
    long long n, i, a, b, c, x;
    long long sum = 0;

    cin >> n >> a >> b >> c >> x;

    for (i = 1; i <= n; i++)
    {
        x = (a * x * x + b * x + c) / 100 % 1'000'000;
        
        if (x % 5 < 2)
        {
            if (q.size() == 0)
            {
                continue;
            }

            if (q.front() == min_q.front())
            {
                min_q.pop_front();
            }
            q.pop_front();
        }
        else
        {
            q.push_back(x);
            while (min_q.size() > 0 && min_q.back() > x)
            {
                min_q.pop_back();
            }
            min_q.push_back(x);
        }

        if (min_q.size() > 0)
        {
            sum += min_q.front();
        }
    }

    cout << sum << "\n";

    return 0;
}
