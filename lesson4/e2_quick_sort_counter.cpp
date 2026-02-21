#include <iostream>
#include <vector>
#include <random>
using namespace std;

int ops = 0;

vector <int> quick_sort(vector <int> arr)
{
    ops++;
    // Base case: if the array has 0 or 1 element, it's already sorted
    if (arr.size() <= 1)
    {
        ops++;
        return arr;
    }

    // Splitting array: elements < pivot (left), elements > pivot (right), and separately elements = pivot
    vector <int> arr_left, arr_pivot, arr_right;
    int pivot = arr[arr.size() / 2];
    for (int i = 0; i < arr.size(); i++)
    {
        ops++;
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
        ops++;
        sorted_arr.push_back(sorted_left[i]);
    }
    for (int i = 0; i < arr_pivot.size(); i++)
    {
        ops++;
        sorted_arr.push_back(arr_pivot[i]);
    }
    for (int i = 0; i < sorted_right.size(); i++)
    {
        ops++;
        sorted_arr.push_back(sorted_right[i]);
    }

    return sorted_arr;
}


vector <int> gen_random(int n)
{
    mt19937 rng(random_device{}());
    vector <int> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rng() % n);
    }

    return arr;
}


vector <int> gen_counter(int n)
{
    vector <int> arr(n);
    arr[n / 2] = 0;
    int i, j;

    i = n / 2 + 1;
    j = n % 2 == 0 ? 1 : 2;
    while (i < n)
    {
        arr[i] = j;
        i++;
        j += 2;
    }

    i = n / 2 - 1;
    j = n % 2 == 0 ? 2 : 1;
    while (i >= 0)
    {
        arr[i] = j;
        i--;
        j += 2;
    }

    return arr;
}



int main()
{
    //vector <int> ns = {10, 20, 35, 65, 80, 100, 200, 350, 650, 800, 1000};
    vector <int> ns = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

    for (int n : ns)
    {
        vector <int> arr_random = gen_random(n);
        ops = 0;
        quick_sort(arr_random);
        cout << "Random array of size " << n << ": " << ops << " operations\n";
    }

    cout << "\n";

    for (int n : ns)
    {
        vector <int> arr_counter = gen_counter(n);
        ops = 0;
        quick_sort(arr_counter);
        cout << "Counter array of size " << n << ": " << ops << " operations\n";
    }

    return 0;
}
