class Solution {
public:
int solve(vector<int>& nums ){
    vector<int> dp (nums.size() + 1);
    int prev = 0;
    int curr = nums[0];

    for(int i = 2 ;  i < nums.size() + 1 ; i++){
        int temp =max( nums[i - 1] + prev,curr);
        prev = curr;
        curr = temp;
    }
    return curr;

}
    int rob(vector<int>& nums) {
        return solve(nums);
    }
};