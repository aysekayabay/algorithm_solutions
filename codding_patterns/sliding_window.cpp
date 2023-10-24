#include <iostream>
#include <vector>

using namespace std;
// FIXED-SIZE SLIDING WINDOW
vector<int> max_sum(vector<int> &nums, int k)
{
    int curr_subarray = 0;

    // sum up the first k elements
    for (int i = 0; i < k; i++)
    {
        curr_subarray += nums[i];
    }

    vector<int> result = {curr_subarray};

    int n = nums.size();

    // slide the window
    for (int i = 1; i < n - k + 1; i++)
    {
        curr_subarray = curr_subarray - nums[i - 1];
        curr_subarray = curr_subarray + nums[i + k - 1];
        result.push_back(curr_subarray);
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    max_sum(nums, k);
    return 0;
}

// DYNMAIC-SIZED SLIDING WINDOW
//  is useful when we don't know the size of the window in advance
int dynamic_sliding_window(vector<int> nums, int x)
{
    int n = nums.size();
    int min_size = INT_MAX;

    int start = 0;
    int end = 0;
    int curr_sum = 0;

    // extend the sliding window until our criteria is met
    while (end < n)
    {
        curr_sum += nums[end];
        end++;
        // shrink the window as small as possible until the 'curr_sum' is smaller than or equal to 'x'
        while (start < end && curr_sum >= x)
        {
            min_size = min(min_size, end - start);
            curr_sum = curr_sum - nums[start];
            start++;
        }
    }

    if (min_size == INT_MAX)
    {
        return 0;
    }
    else
    {
        return min_size;
    }
}