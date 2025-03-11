class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
      long long ans = 0;
      int mink= -1 , maxk=-1,c_i=-1;
      for(int i = 0 ; i < nums.size() ; i++)
      {
        if(nums[i]<minK || nums[i]> maxK)
            c_i=i;

        if(nums[i]==minK)
            mink = i;
        
        if(nums[i]==maxK)
            maxk=i;
        
        auto s = min(mink,maxk);
        auto temp = s - c_i;

        ans +=(temp<=0) ? 0 : temp;
      }  
      return ans;
    }
};