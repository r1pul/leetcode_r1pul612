class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = bs(nums, 0);
        int pos = nums.size() - bs(nums, 1);
        return max(pos, neg);
    }
    int bs(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int res = nums.size();
        while (l <= r) {
            int mid = (l + r) / 2;

            if (nums[mid] < target)
                l = mid + 1;

            else {
                res = mid;
                r = mid - 1;
            }
        }
        return res;
    }
};