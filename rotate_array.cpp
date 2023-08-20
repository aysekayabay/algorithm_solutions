class Solution {
public:
    void rotate(vector<int>& nums, int k) {  // my solution
        int size = nums.size();
        vector<int> sub;
        k = k % size;
        int iter = size - k;
        sub.insert(sub.end(), nums.begin() + iter, nums.end());
        nums.erase(nums.begin() + iter, nums.end());
        nums.insert(nums.begin(), sub.begin(), sub.end());
    }

    void rotate(vector<int> &nums,int k){ // other solution from leetcode
        int n=nums.size();
        k=k%n;
        vector<int> temp(n,0);
        for(int i=0;i<k;i++){
            temp[i]=nums[n-k+i];
        }
        for(int i=0;i<n-k;i++){
            temp[k+i]=nums[i];
        }
        nums=temp;
    }
};