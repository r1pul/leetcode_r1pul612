class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0)
            return nums;
        int n  = nums.size();
        vector<int> result(n,-1);
        int left = 0 ,  right = 2 * k;
        int i = k;
        if(2*k +1 > n)
            return result;
        long long window  = 0;
        for(int i = 0 ;  i <= right ; i++)
            window += nums[i];

        int total = 2 * k +1;
        result[i] = window/total;
        i++;
        right++;    
        while(right < n){
            int out = nums[left];
            int in = nums[right];

            window += in - out;
            result[i] = window/total;
            right++;
            left++;
            i++;
        }
        return result;
    }
};