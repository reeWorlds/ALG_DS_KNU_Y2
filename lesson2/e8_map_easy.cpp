#include <iostream>
#include <map>
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
    map <int, int> mp;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        mp[x]++;
        cout << "Number " << x << " has occurred " << mp[x] << " times\n";
    }

    cout << "Map contents (iterators):";
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << " {" << it->first << ": " << it->second << "}";
    }
    cout << "\n";

    cout << "Map contents (range-based for):";
    for (auto p : mp)
    {
        cout << " {" << p.first << ": " << p.second << "}";
    }
    cout << "\n";

    return 0;
}