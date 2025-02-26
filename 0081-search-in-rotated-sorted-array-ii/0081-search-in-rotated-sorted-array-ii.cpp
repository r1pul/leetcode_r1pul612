class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int p = findp(nums, n - 1, 0);
         
        if (bs(nums, p - 1, 0,target))
           return 1;

        return bs(nums, n - 1, p, target);
    }
    bool bs(vector<int>& nums, int r, int l, int& target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;

            if (nums[mid] < target)
                l = mid + 1;

            else
                r = mid - 1;
        }
        return false;
    }
    int findp(vector<int>& nums, int r, int l) {
        while (l < r) {
            while (l < r && nums[l] == nums[l + 1])
                l++;
            while (l < r && nums[r] == nums[r - 1])
                r--;

            int mid = l+(r - l) / 2;
            if (nums[mid] <= nums[r])
                r = mid;

            else
                l = mid + 1;
        }
        return r;
    }
};