#include <iostream>
// #include <queue> // just use deque, lol
#include <deque>
using namespace std;

/*
10
+ 1
+ 2
+ 7
-
+ 3
-
-
+ 4
+ 1
+ 9

*/

int main()
{
    char op;
    int t, n, i;

    int total_time = 0;
    deque <int> q;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> op;
        if (op == '+')
        {
            cin >> t;
            q.push_back(t);
            total_time += t;
        }
        else if (op == '-')
        {
            total_time -= q.front();
            q.pop_front();
        }
        
        cout << "Remaining queue time: " << total_time << "\n\n";
    }

    return 0;
}


