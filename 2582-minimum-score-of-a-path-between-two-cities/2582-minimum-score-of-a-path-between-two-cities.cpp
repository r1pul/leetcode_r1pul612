class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto& vec : roads){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            mp[u].push_back({v,w});
            mp[v].push_back({u,w});
        }
        vector<bool>visited(n,false);
        int res = INT_MAX;
        dfs(mp,visited,res,1);
        return res;
    }
    void dfs(unordered_map<int,vector<pair<int,int>>>& mp, vector<bool>& visited, int& res, int u){
        visited[u]=true;
        for(auto& vec : mp[u]){
            int v = vec.first;
            int w = vec.second;
            res=min(res,w);
            if(!visited[v])
            dfs(mp,visited,res,v);
        }
    }
};