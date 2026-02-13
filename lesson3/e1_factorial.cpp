#include <iostream>
using namespace std;

int f(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * f(n - 1);
}

int main()
{
    for (int i = 0; i < 7; i++)
    {
        cout << i << "! = " << f(i) << "\n";
    }

    return 0;
}