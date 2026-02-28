#include <iostream>
#include <vector>
using namespace std;

int max_sum_subarray(vector <int> arr)
{
    // Base case: array of size 1
    if (arr.size() == 1)
    {
        return arr[0];
    }

    // Splitting array: left and right halves
    int mid = arr.size() / 2;
    vector <int> arr_left, arr_right;
    for (int i = 0; i < mid; i++)
    {
        arr_left.push_back(arr[i]);
    }
    for (int i = mid; i < arr.size(); i++)
    {
        arr_right.push_back(arr[i]);
    }

    // Maximum subarray sum on left and right halves (recursively)
    int max_left_sum = max_sum_subarray(arr_left);
    int max_right_sum = max_sum_subarray(arr_right);
    
    // Maximum subarray sum crossing the midpoint
    int max_sum_left_of_mid = arr[mid - 1], max_sum_right_of_mid = arr[mid], tmp_sum;
    tmp_sum = 0;
    for (int i = mid - 1; i >= 0; i--)
    {
        tmp_sum += arr[i];
        max_sum_left_of_mid = max(max_sum_left_of_mid, tmp_sum);
    }
    tmp_sum = 0;
    for (int i = mid; i < arr.size(); i++)
    {
        tmp_sum += arr[i];
        max_sum_right_of_mid = max(max_sum_right_of_mid, tmp_sum);
    }
    int max_cross_sum = max_sum_left_of_mid + max_sum_right_of_mid;
    
    // Combining all cases
    int max_sum = max(max(max_left_sum, max_right_sum), max_cross_sum);

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

    int max_sum = max_sum_subarray(arr);
    cout << "Maximum subarray sum: " << max_sum << "\n";

    return 0;
}
