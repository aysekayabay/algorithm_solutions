class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)  return n;
        int currentIndex = 2;  
        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[currentIndex - 1] || nums[i] != nums[currentIndex - 2]) {
                nums[currentIndex] = nums[i];
                currentIndex++;
            }
        }
        nums.resize(currentIndex);
        return currentIndex;
    }
};