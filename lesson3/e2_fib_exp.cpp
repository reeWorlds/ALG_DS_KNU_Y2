#include <iostream>
using namespace std;

int cnt_ops;

int fib(int n)
{
    cnt_ops++;
    if (n <= 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}


int main()
{
    for (int i = 1; i < 30; i+=4)
    {
        cnt_ops = 0;
        cout << "fib(" << i << ") = " << fib(i) << "  (" << cnt_ops << " ops)" << "\n";
    }

    return 0;
}