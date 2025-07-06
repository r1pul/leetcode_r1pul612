class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>output;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }
        for(auto& vec : mp){
            if(vec.second>n/3)
            output.push_back(vec.first);


        }
        return output;
    }
};