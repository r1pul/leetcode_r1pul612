class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> Map;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int c = target - nums[i];
            if (Map.count(c)) {
                return {Map[c], i};
            }
            Map[nums[i]] = i;
        }

        return {};
    }
};