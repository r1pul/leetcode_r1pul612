class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false; // Handle the case of empty input
        
        int p = findPivot(nums, n - 1, 0);
        
        // Perform binary search in the two possible halves
        return binarySearch(nums, 0, p - 1, target) || binarySearch(nums, p, n - 1, target);
    }
    
    bool binarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            // Handle duplicates
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } 
            else if (nums[mid] <= nums[right]) {
                // Right portion is sorted
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                // Left portion is sorted
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return false; // target not found
    }
    
    int findPivot(vector<int>& nums, int right, int left) {
        while (left < right) {
            while (left < right && nums[left] == nums[left + 1]) left++;
            while (left < right && nums[right] == nums[right - 1]) right--;

            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left; // pivot index
    }
};
