#include <iostream>
#include <string>
// #include <stack> // just use vector, lol
#include <vector>
using namespace std;

// (()[(()([()]))])
// ([()())]()
// ([()()])()(([

int main()
{
    string s;

    cin >> s;

    vector <char> stack;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[')
        {
            stack.push_back(s[i]);
        }
        else
        {
            char opposite = s[i] == ')' ? '(' : '[';
            if (stack.empty() || stack.back() != opposite)
            {
                cout << "Sequence is unbalanced\n";
                return 0;
            }
            else
            {
                stack.pop_back();
            }

        }
    }

    if (stack.empty())
    {
        cout << "Sequence is balanced\n";
    }
    else
    {
        cout << "Sequence is unbalanced\n";
    }

    return 0;
}


