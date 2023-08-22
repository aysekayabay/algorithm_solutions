class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size=nums.size();
        int maxIter = 0;
        for(int i=0;i<size;i++){
            if (i > maxIter) {
                return false;
            }
            maxIter = max(maxIter, i + nums[i]);
            if (maxIter >= size - 1) {
                return true;
            }
        }
        return false;
    }
};