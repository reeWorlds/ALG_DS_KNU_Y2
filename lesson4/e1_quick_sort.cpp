#include <iostream>
#include <vector>
#include <random>
using namespace std;


vector <int> quick_sort(vector <int> arr)
{
    // Base case: if the array has 0 or 1 element, it's already sorted
    if (arr.size() <= 1)
    {
        return arr;
    }

    // Splitting array: elements < pivot (left), elements > pivot (right), and separately elements = pivot
    vector <int> arr_left, arr_pivot, arr_right;
    int pivot = arr[arr.size() / 2];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < pivot)
        {
            arr_left.push_back(arr[i]);
        }
        else if (arr[i] == pivot)
        {
            arr_pivot.push_back(arr[i]);
        }
        else
        {
            arr_right.push_back(arr[i]);
        }
    }

    // Recursively sort the left and right subarrays
    vector <int> sorted_left = quick_sort(arr_left);
    vector <int> sorted_right = quick_sort(arr_right);

    // Concatenate sorted left, pivot, and sorted right to get the final sorted array
    vector <int> sorted_arr;
    for (int i = 0; i < sorted_left.size(); i++)
    {
        sorted_arr.push_back(sorted_left[i]);
    }
    for (int i = 0; i < arr_pivot.size(); i++)
    {
        sorted_arr.push_back(arr_pivot[i]);
    }
    for (int i = 0; i < sorted_right.size(); i++)
    {
        sorted_arr.push_back(sorted_right[i]);
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

    vector <int> sorted_arr = quick_sort(arr);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << sorted_arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
