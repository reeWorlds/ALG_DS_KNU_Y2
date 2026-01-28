#include <iostream>
#include <random>
using namespace std;

int cnt_ops = 0;

void rec(int n, int pos)
{
    if (pos > n)
    {
        cnt_ops++;
        return;
    }

    cnt_ops++;
    rec(n, pos + 1);
    rec(n, pos + 1);
}


int main()
{
    int n = 10;

    rec(n, 1);
    cout << "Performed " << cnt_ops << " operations\n";

    return 0;
}
