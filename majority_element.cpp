
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    { // Boyer-Moore Voting Algorithm O(n) time, O(1) space complexity. Saved for myself.
        int element = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
                element = nums[i];
            count += (element == nums[i]) ? 1 : -1;
        }
        return element;
    }

    int myMajorityElementSolution(vector<int> &nums)
    {
        map<int, int> freqs;
        for (int num : nums)
        {
            freqs[num]++;
            if (freqs[num] >= nums.size() / 2 + 1)
            {
                return num;
            }
        }
        return 0;
    }
};