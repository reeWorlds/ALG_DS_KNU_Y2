#include <iostream>
#include <random>
using namespace std;

int cnt_ops = 0;

double L = 0.0, R = 1'000.0, EPS = 1e-7;     

double f(double x)
{
    return x * x + x * x * x - 6;
}

double bin_search()
{
    double l = L, r = R;

    while (r - l > EPS)
    {
        cnt_ops++;
        double m = (l + r) / 2;
        if (f(m) < 0)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    
    return (l + r) / 2;
}


int main()
{
    cout.precision(10);
    cout << "Root of f(x) = x^2 + x^3 - 6 is around " << fixed << bin_search() << "\n";
    cout << "Performed " << cnt_ops << " operations\n";

    return 0;
}
