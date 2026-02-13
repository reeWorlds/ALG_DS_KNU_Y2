#include <iostream>
using namespace std;

int gcd_lin(int a, int b)
{
    int max_div = 1;
    for (int i = 2; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            max_div = i;
        }
    }
    return max_div;
}


int main()
{
    int a, b;
    cin >> a >> b;

    cout << "gcd(" << a << ", " << b << ") = " << gcd_lin(a, b) << "\n";

    return 0;
}