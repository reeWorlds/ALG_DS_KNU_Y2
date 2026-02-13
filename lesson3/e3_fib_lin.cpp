#include <iostream>
using namespace std;

int cnt_ops;

int _fib[100]; // Also, initialize _fib with -1

int fib(int n)
{
    cnt_ops++;
    if (n <= 1) {return 1;}
    if (_fib[n] == -1)
    {
        _fib[n] = fib(n - 1) + fib(n - 2);
    }
    return _fib[n];
}


int main()
{
    for (int i = 1; i < 30; i+=4)
    {
        cnt_ops = 0;
        for (auto &x : _fib) {x = -1;}

        cout << "fib(" << i << ") = " << fib(i) << "  (" << cnt_ops << " ops)" << "\n";
    }

    return 0;
}