#include <iostream>
#include <chrono>
using namespace std;


int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}


int main()
{
    long long avoid_optimization = 0;
    cout.precision(8);

    for (int i = 0; i < 50; i++)
    {
        auto start_t = chrono::high_resolution_clock::now();
        int result = fib(i);
        auto end_t = chrono::high_resolution_clock::now();
        auto duration = chrono::duration<double>(end_t - start_t).count();
        cout << i << " " << fixed << duration << "\n";
        avoid_optimization += result;   
    }
    cout << "Sum of Fibonacci numbers: " << avoid_optimization << "\n";

    return 0;
}
