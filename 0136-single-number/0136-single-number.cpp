class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int n = nums.size();
       unordered_map<int,int> st;
       for(auto& it : nums)
       {
        st[it]++;

       }
       for(auto& it : st)
       {
        if(it.second==1)
        return it.first;
       }
return -1;
    }
};