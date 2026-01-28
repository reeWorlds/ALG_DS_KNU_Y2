#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

int cnt_op = 0;


void count_sort(int* arr, int n)
{
    int max_a = arr[0];
    for (int i = 1; i < n; i++)
    {
        cnt_op++;
        max_a = max(max_a, arr[i]);
    }
    int* count = new int[max_a + 1];
    for (int i = 0; i <= max_a; i++)
    {
        cnt_op++;
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cnt_op++;
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_a; i++)
    {
        while (count[i] > 0)
        {
            cnt_op++;
            arr[index++] = i;
            count[i]--;
        }
    }
    delete[] count;
}


int main()
{
    int n = 20;
    int* arr = new int[n];

    mt19937 rng(random_device{}());
    for (int i = 0; i < n; i++)
    {
        arr[i] = rng() % 20;
    }

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    count_sort(arr, n);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    cout << "Number of operations: " << cnt_op << "\n";
    
    delete[] arr;

    return 0;
}
