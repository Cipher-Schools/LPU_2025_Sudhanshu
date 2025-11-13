/*
Given an array nums of n integers and an integer k, determine whether there exist two adjacent subarrays of length k such that both subarrays are strictly increasing. Specifically, check if there are two subarrays starting at indices a and b (a < b), where:

Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
The subarrays must be adjacent, meaning b = a + k.
Return true if it is possible to find two such subarrays, and false otherwise.
*/

#include <iostream>
using namespace std;

bool hasIncreasingSubarrays(int nums[], int k)
{
    int n = sizeof(nums) / sizeof(nums[0]);
    int inc = 1;
    int prevInc = 0;
    int maxLen = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
            inc++;
        else
        {
            prevInc = inc;
            inc = 1;
        }
        prevInc = min(prevInc, inc);
        maxLen = max(maxLen, max(inc >> 1, prevInc));
        if (maxLen >= k)
            return true;
    }
    return false;
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int k;

    cout << "Enter the value of k: ";
    cin >> k;

    bool result = hasIncreasingSubarrays(nums, k);
    if (result)
    {
        cout << "There exist two adjacent strictly increasing subarrays of length " << k << "." << endl;
    }
    else
    {
        cout << "No such adjacent strictly increasing subarrays of length " << k << " exist." << endl;
    }

    return 0;
}