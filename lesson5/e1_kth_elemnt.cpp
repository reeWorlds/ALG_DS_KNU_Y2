#include <iostream>
#include <vector>
using namespace std;

int kth_element(vector<int> nums, int k)
{
    // Base case: array of size 1
    if (nums.size() == 1)
    {
        return nums[0];
    }

    // Splitting array: left and right halves (+ center)
    int pivot = nums[nums.size() / 2];
    vector <int> nums_left, nums_center, nums_right;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < pivot)
        {
            nums_left.push_back(nums[i]);
        }
        else if (nums[i] == pivot)
        {
            nums_center.push_back(nums[i]);
        }
        else
        {
            nums_right.push_back(nums[i]);
        }
    }

    // Determine which partition contains the k-th largest element
    if (k <= nums_right.size())
    {
        return kth_element(nums_right, k);
    }
    else if (k <= nums_right.size() + nums_center.size())
    {
        return pivot; // return kth_element(nums_center, k - nums_right.size());
    }
    else
    {
        return kth_element(nums_left, k - nums_right.size() - nums_center.size());
    }
}

/*
9 4 
3 2 3 1 2 4 5 5 6
*/


int main()
{
    int n, k, i, a;
    vector <int> nums;

    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        nums.push_back(a);
    }

    int kth = kth_element(nums, k);
    cout << "The " << k << "-th largest element is: " << kth << "\n";

    return 0;
}
