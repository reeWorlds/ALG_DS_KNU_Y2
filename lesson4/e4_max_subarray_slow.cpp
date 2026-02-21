#include <iostream>
#include <vector>
using namespace std;


int max_sum_subarray_n3(vector <int> arr)
{
    int max_sum = arr[0];

    for (int l = 0; l < arr.size(); l++)
    {
        for (int r = l; r < arr.size(); r++)
        {
            int sum = 0;
            for (int i = l; i <= r; i++)
            {
                sum += arr[i];
            }
            max_sum = max(max_sum, sum);
        }
    }

    return max_sum;
}


int max_sum_subarray_n2(vector <int> arr)
{
    int max_sum = 0;

    for (int l = 0; l < arr.size(); l++)
    {
        int sum = 0;

        for (int r = l; r < arr.size(); r++)
        {
            sum += arr[r];
            max_sum = max(max_sum, sum);
        }
    }

    return max_sum;
}

/*
12
3 -5 9 1 -4 2 -1 -4 4 7 -2 -6
*/


int main()
{
    int n, i, a;
    vector <int> arr;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }

    int max_sum_n3 = max_sum_subarray_n3(arr);
    int max_sum_n2 = max_sum_subarray_n2(arr);
    cout << "Maximum subarray sum O(n^3): " << max_sum_n3 << "\n";
    cout << "Maximum subarray sum O(n^2): " << max_sum_n2 << "\n";

    return 0;
}
