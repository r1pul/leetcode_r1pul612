class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n);
        for(int i = 1 ; i < n ; i++)
        {
            nums[i] += nums[i-1];
            

        }
        return nums;
    }
};