#include <iostream>
#include <vector>
using namespace std;

int cnt_formula(vector <int> left, vector <int> right, int c)
{
    // Base case: one array of size 1
    if (left.size() == 1 || right.size() == 1)
    {
        int cnt = 0;
        for (int i = 0; i < left.size(); i++)
        {
            for (int j = 0; j < right.size(); j++)
            {
                if (left[i] * left[i] + left[i] * right[j] + right[j] * right[j] == c)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }

    // Splitting each array: left and right halves
    int mid = left.size() / 2;
    vector <int> left_left, left_right;
    for (int i = 0; i < mid; i++)
    {
        left_left.push_back(left[i]);
    }
    for (int i = mid; i < left.size(); i++)
    {
        left_right.push_back(left[i]);
    }
    mid = right.size() / 2;
    vector <int> right_left, right_right;
    for (int i = 0; i < mid; i++)
    {
        right_left.push_back(right[i]);
    }
    for (int i = mid; i < right.size(); i++)
    {
        right_right.push_back(right[i]);
    }

    // Count on left and right halves (recursively)
    int cnt_left_left = cnt_formula(left_left, right_left, c);
    int cnt_left_right = cnt_formula(left_left, right_right, c);
    int cnt_right_left = cnt_formula(left_right, right_left, c);
    int cnt_right_right = cnt_formula(left_right, right_right, c);

    int sum = cnt_left_left + cnt_left_right + cnt_right_left + cnt_right_right;

    return sum;
}

/*
5 19
2 3 1 4 3
*/


int main()
{
    int n, i, a, c;
    vector <int> arr;

    cin >> n >> c;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    
    int result = cnt_formula(arr, arr, c);
    cout << "Count: " << result << "\n";

    return 0;
}
