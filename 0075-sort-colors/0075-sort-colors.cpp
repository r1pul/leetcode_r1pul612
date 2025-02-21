class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j =0;
        int k = n-1;
        while(i<=k)
        {
            if(nums[i] == 1)
            i++;
            else if(nums[i]==2){
            swap(nums[i],nums[k]);
            k--;
            }

            else{
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
    }
};