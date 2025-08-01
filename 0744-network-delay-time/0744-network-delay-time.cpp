class Solution {
public:
    typedef pair<int,int> p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<p>> mp;
        for(auto& vec : times){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            mp[u].push_back({v,w});
        }
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<int>res(n+1,INT_MAX);
        res[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int v = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            for(auto& vec : mp[v]){
                int v_ = vec.first;
                int w_ = vec.second;
                if(w+w_  < res[v_]){
                    res[v_]=w+w_;
                    pq.push({w+w_,v_});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1 ; i <= n ; i++){
            ans=max(ans,res[i]);
        }
        return ans==INT_MAX ?-1:ans;
        
    }
};