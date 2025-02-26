class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxn = nums[0];
        int minn = nums[0];
        int curr = nums[0];

        for (int i = 1; i < n; i++) {

            curr = max(nums[i], curr + nums[i]);
            maxn = max(maxn, curr);
        }
        curr = nums[0];
        for (int i = 1; i < n; i++) {

            curr = min(nums[i], curr + nums[i]);
            minn = min(curr, minn);
        }

        return max(maxn, abs(minn));
    }
};