class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0 ; 
        int j = 0 ; 
        int k = nums.size()-1;
        while(i<=k){
            if(nums[i]==1)
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