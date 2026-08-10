class Solution {
public:
int solve(vector<int>& nums , int curr){
    vector<int> dp (nums.size() + 1);
    dp[0] = 0;
    dp[1] = nums[0];

    for(int i = 2 ;  i < nums.size() + 1 ; i++){
        int take = dp[i - 2] + nums[i-1];
        int skip = dp[i-1];
        dp[i] = max(take,skip);
    }
    return dp[nums.size() ];

}
    int rob(vector<int>& nums) {
        return solve(nums,0);
    }
};