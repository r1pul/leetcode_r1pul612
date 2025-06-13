class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums[n-1]-nums[0];
        while(l<r){
            int m = l +( r-l )/2;
            int pi = 0;
            for(int i = 1 ; i < n ; ++i){
                if(nums[i] - nums[i-1]<= m){
                    ++pi;
                    ++i;
                }
               
            }
             if(pi>=p)
                r=m;
            else
                l=m+1;
            
        }
        return l;
    }
};