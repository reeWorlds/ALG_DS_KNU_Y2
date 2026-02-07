#include <iostream>
#include <set>
using namespace std;

/*
10
1
5
6
1
7
7
5
3
1
7

*/


int main()
{
    int n, i, x;
    set <int> s;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
        cout << "Total unique numbers: " << s.size() << "\n";
    }

    cout << "Set contents (iterators):";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << " " << *it;
    }
    cout << "\n";

    cout << "Set contents (range-based for):";
    for (int v : s)
    {
        cout << " " << v;
    }
    cout << "\n";

    return 0;
}