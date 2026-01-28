#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

int cnt_ops = 0;

int* arr = new int[1];
int capacity = 1;
int sz = 0;

void add(int val)
{
    if (sz == capacity)
    {
        cnt_ops++;
        capacity *= 2;
        int* new_arr = new int[capacity];
        for (int i = 0; i < sz; i++)
        {
            new_arr[i] = arr[i];
            cnt_ops++;
        }
        delete[] arr;
        arr = new_arr;
    }

    arr[sz] = val;
    sz++;
    cnt_ops++;
}

int main()
{
    int n = 1'000;

    for (int i = 1; i <= n; i++)
    {
        add(i);
    }
    cout << "Number of operations: " << cnt_ops << "\n";

    delete[] arr;

    return 0;
}
