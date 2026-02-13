#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0) {return b;}
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int lcm_dangerous(int a, int b)
{
    return a * b / gcd(a, b);
}


int main()
{
    int a = 130'000, b = 150'000;

    cout << "lcm(" << a << ", " << b << ") = " << lcm(a, b) << "\n";
    cout << "lcm_dangerous(" << a << ", " << b << ") = " << lcm_dangerous(a, b) << "\n";

    return 0;
}