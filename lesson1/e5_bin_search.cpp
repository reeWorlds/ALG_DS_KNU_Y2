#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

int cnt_ops = 0;

int bin_search(int* arr, int n, int target)
{
    int l = 0, r = n;

    while (l != r)
    {
        cnt_ops++;

        int m = (l + r) / 2;
        if (arr[m] < target)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    
    return l;
}


int main()
{
    int n = 10;
    int* arr = new int[n];

    mt19937 rng(random_device{}());
    for (int i = 0; i < n; i++)
    {
        arr[i] = rng() % 50;
    }

    sort(arr, arr + n);
    cout << "After sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    int idx = rng() % n;
    int target = arr[idx];
    cout << ">= " << target << " at index " << bin_search(arr, n, target) << "\n";

    cout << "Number of operations: " << cnt_ops << "\n";
    
    delete[] arr;

    return 0;
}
