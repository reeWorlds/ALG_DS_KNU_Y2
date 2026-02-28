#include <iostream>
#include <random>
using namespace std;


int avoid_optimization = 0;


int factorize_all(int n)
{
    int cnt_ops = 0;
    int sum_cnt_factors = 0;

    for (int i = n / 2; i <= n; i++)
    {
        int cnt_factors = 0, _i = i;
        for (int j = 2; j * j <= _i; j++)
        {
            cnt_ops++;
            while (_i % j == 0)
            {
                cnt_factors++;
                _i /= j;
                cnt_ops++;
            }
        }
        if (_i > 1)
        {
            cnt_factors++;
            cnt_ops++;
        }
    }

    avoid_optimization += sum_cnt_factors;
    return cnt_ops;
}


int main()
{
    vector <int> ns;
    for (int i = 1; i <= 30; i++)
    {
        ns.push_back(i * 10'000);
    }

    for (int n : ns)
    {
        int avg_cnt_ops = factorize_all(n) * 2 / n;
        cout << n << " " << avg_cnt_ops << "\n";
    }

    return 0;
}
