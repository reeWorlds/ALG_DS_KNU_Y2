#include <iostream>
#include <random>
using namespace std;

int cnt_op = 0;

void bubble_sort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cnt_op++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                cnt_op++;
            }
        }
    }
}


int main()
{
    int n = 10;
    int* arr = new int[n];

    mt19937 rng(random_device{}());
    for (int i = 0; i < n; i++)
    {
        arr[i] = rng() % 10;
    }

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    bubble_sort(arr, n);

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
