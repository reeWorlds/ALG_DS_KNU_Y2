#include <iostream>
using namespace std;

int gcd_ext(int a, int b, int &x1, int &y1)
{
    // Given a and b, find x1 and y1
    // such that a*x1 + b*y1 = gcd(a, b)
    if (b == 0)
    {
        x1 = 1; y1 = 0;
        return a;
    }

    int x2, y2;
    int d = gcd_ext(b, a % b, x2, y2);
    x1 = y2;
    y1 = x2 - (a / b) * y2;

    return d;
}


int main()
{
    int a, b, x, y;
    cin >> a >> b;

    int d = gcd_ext(a, b, x, y);

    cout << "a = " << a << ", b = " << b << "\n";
    cout << "gcd(a, b) = " << d << "\n";
    cout << "x = " << x << ", y = " << y << "\n";

    cout << "Check: a*x + b*y = " << a * x + b * y << "\n";

    return 0;
}