class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        priority_queue<pair<int,int>> que;
        for(int i = 0 ; i < n ; i++){
            que.push({nums[i],i});
            if(i>=(k-1)){
                while(i-que.top().second >=k)
                que.pop();

                ans.push_back(que.top().first);
            }
        }
        return ans;
    }
};