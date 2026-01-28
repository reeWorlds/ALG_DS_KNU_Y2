#include <iostream>
#include <random>
using namespace std;

int cnt_ops;

long long sum(int n)
{
    if (n < 100)
    {
        long long sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += i;
            cnt_ops++;
        }
        return sum;
    }
    else
    {
        long long llN = n;
        cnt_ops++;
        return llN * (llN + 1) / 2;
    }
}


int main()
{
    mt19937 rng(random_device{}());

    int n = rng() % 200 + 1;

    cout << "Sum 1.." << n << ": " << sum(n) << "\n";
    cout << "Performed " << cnt_ops << " operations\n";


    return 0;
}
