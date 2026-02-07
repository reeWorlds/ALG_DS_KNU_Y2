#include <iostream>
#include <string>
// #include <stack> // just use vector, lol
#include <vector>
using namespace std;

string intoString(vector <char> stack)
{
    string result = "";
    for (char c : stack)
    {
        result += c;
    }
    return result;
}

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
            cout << "Pushed " << s[i] << "\n";
            cout << "Stack now: " << intoString(stack) << "\n\n";
        }
        else
        {
            char opposite = s[i] == ')' ? '(' : '[';
            if (stack.empty() || stack.back() != opposite)
            {
                cout << "Encountered " << s[i] << " when stack was " << intoString(stack) << "\n";
                cout << "Sequence is unbalanced\n";
                return 0;
            }
            else
            {
                stack.pop_back();
                cout << "Popped " << s[i] << "\n";
                cout << "Stack now: " << intoString(stack) << "\n\n";
            }
        }
    }

    if (stack.empty())
    {
        cout << "Stack is empty at the end\n";
        cout << "Sequence is balanced\n";
    }
    else
    {
        cout << "Stack is not empty at the end: " << intoString(stack) << "\n";
        cout << "Sequence is unbalanced\n";
    }

    return 0;
}
