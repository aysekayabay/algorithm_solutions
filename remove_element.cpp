#include <vector>
#include <iostream>

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[count] = nums[i];
                count++;
            }
        }
        nums.resize(count);
        return nums.size();
    }
};