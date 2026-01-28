#include <iostream>
#include <random>
using namespace std;

int cnt_ops = 0;

int factorize(int a)
{
    int cnt_factors = 0;
    
    for (int i = 2; i * i <= a; i++)
    {
        cnt_ops++;
        while (a % i == 0)
        {
            cnt_factors++;
            a /= i;
            cnt_ops++;
        }
    }
    if (a > 1)
    {
        cnt_factors++;
        cnt_ops++;
    }

    return cnt_factors;
}


int main()
{
    int n = 1'000;

    mt19937 rng(random_device{}());

    int a = rng() % (n / 2) + n / 2; // random number from [n/2, n)

    cout << a << " has " << factorize(a) << " factors\n";

    cout << "Number of operations: " << cnt_ops << "\n";

    return 0;
}
