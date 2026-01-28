#include <iostream>
#include <random>
using namespace std;

int cnt_ops = 0;

int lin_search(int* arr, int n, int target)
{
    cnt_ops = 0;
    for (int i = 0; i < n; i++)
    {
        cnt_ops++;
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    int n = 1'000;
    int* arr = new int[n];

    mt19937 rng(random_device{}());
    for (int i = 0; i < n; i++)
    {
        arr[i] = rng() % 1'000'000;
    }

    int num1 = arr[rng() % n];
    int idx1 = lin_search(arr, n, num1); 
    cout << "Index of num1: " << idx1 << "\n";
    cout << "Performed " << cnt_ops << " operations\n";

    int num2 = arr[rng() % 10];
    int idx2 = lin_search(arr, n, num2); 
    cout << "Index of num2: " << idx2 << "\n";
    cout << "Performed " << cnt_ops << " operations\n";

    int num3 = rng() % 1'000'000;
    int idx3 = lin_search(arr, n, num3); 
    cout << "Index of num3: " << idx3 << "\n";
    cout << "Performed " << cnt_ops << " operations\n";

    delete[] arr;

    return 0;
}
