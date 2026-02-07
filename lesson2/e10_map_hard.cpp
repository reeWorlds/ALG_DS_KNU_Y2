#include <iostream>
#include <map>
using namespace std;

/*
11 7
1
-100007
3
4
10
6
7
3
-100000
-3
4

*/


int main()
{
    int n, k, i, x;
    map<int, int> m;

    long long total = 0;

    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        
        total += m[k - x];
        m[x]++;

        cout << "Number of pairs with sum " << k << " is " << total << "\n";
    }

    return 0;
}
