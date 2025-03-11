class Solution {
public:
bool ispossible(vector<int>& nums, int k , int mid)
{ 
    int c =1,sum =0;
    for(int i =0 ; i<nums.size(); i++)
    {
        if(nums[i]>mid)
        { return false;
        }
        if(nums[i]+sum>mid)
        {
             c++;
            sum = nums[i];
           
            if(c>k)
            return false;
        }
        else
        sum+=nums[i];

    }
    return true;

}

    int splitArray(vector<int>& nums, int k) {
        int s =0, e = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            
            if(ispossible(nums,k,mid))
            {
                ans=mid;
                e = mid - 1;
            }
            else{
                s =mid + 1;
            }
        }
        return ans;

        
    }
};