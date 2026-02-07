#include <iostream>
#include <set>
using namespace std;

/*
10
+ 5
+ 7
+ 3
? 5
? 4
+ 2
? 1
? 9
+ 7
? 6

*/


int main()
{
    int n, i, x;
    char c;

    set<int> s;
    set<int>::iterator it;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> c >> x;
        if (c == '+')
        {
            s.insert(x);
        }
        else if (c == '?')
        {
            it = s.upper_bound(x);
            if (it != s.end())
            {
                cout << *it << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}
