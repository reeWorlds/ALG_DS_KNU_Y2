#include <iostream>
using namespace std;

int cnt_ops;

long long sumON(int n)
{
    cnt_ops = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
        cnt_ops++;
    }
    return sum;
}

long long sumO1(int n)
{
    cnt_ops = 0;
    long long llN = n;
    cnt_ops++;
    return llN * (llN + 1) / 2;
}

long long sumO2(int n)
{
    cnt_ops = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt_ops++;
        for (int j = 1; j <= i; j++)
        {
            cnt_ops++;
            sum++;
        }
    }
    return sum;
}


int main()
{
    int n = 100;

    cout << "Sum 1..n using O(N): " << sumON(n) << "\n";
    cout << "Performed " << cnt_ops << " operations\n";

    cout << "Sum 1..n using O(1): " << sumO1(n) << "\n";
    cout << "Performed " << cnt_ops << " operations\n";

    cout << "Sum 1..n using O(N^2): " << sumO2(n) << "\n";
    cout << "Performed " << cnt_ops << " operations\n";

    return 0;
}


