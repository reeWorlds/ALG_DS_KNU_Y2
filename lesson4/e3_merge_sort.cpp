#include <iostream>
#include <vector>
#include <random>
using namespace std;


vector <int> merge_sort(vector <int> arr)
{
    // Base case: if the array has 0 or 1 element, it's already sorted
    if (arr.size() <= 1)
    {
        return arr;
    }

    // Splitting array: lest and right halves
    vector <int> arr_left, arr_right;
    int mid = arr.size() / 2;
    for (int i = 0; i < mid; i++)
    {
        arr_left.push_back(arr[i]);
    }
    for (int i = mid; i < arr.size(); i++)
    {
        arr_right.push_back(arr[i]);
    }

    // Recursively sort the left and right subarrays
    vector <int> sorted_left = merge_sort(arr_left);
    vector <int> sorted_right = merge_sort(arr_right);

    // Merge sorted left and right to get the final sorted array
    vector <int> sorted_arr;
    int i = 0, j = 0;
    while (i < sorted_left.size() && j < sorted_right.size())
    {
        if (sorted_left[i] < sorted_right[j])
        {
            sorted_arr.push_back(sorted_left[i]);
            i++;
        }
        else
        {
            sorted_arr.push_back(sorted_right[j]);
            j++;
        }
    }
    while (i < sorted_left.size())
    {
        sorted_arr.push_back(sorted_left[i]);
        i++;
    }
    while (j < sorted_right.size())
    {
        sorted_arr.push_back(sorted_right[j]);
        j++;
    }

    return sorted_arr;
}



int main()
{
    mt19937 rng(random_device{}());

    int n = 10;
    vector <int> arr;

    for (int i = 0; i < n; i++)
    {
        arr.push_back(rng() % n);
    }

    cout << "Original array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    vector <int> sorted_arr = merge_sort(arr);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << sorted_arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
