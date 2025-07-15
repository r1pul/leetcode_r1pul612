class Solution {
public:
int count = 0;
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool>visited(n,false);
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto& vec : connections){
            mp[vec[0]].push_back({vec[1],1});
            mp[vec[1]].push_back({vec[0],0});
        }
        dfs(0,-1,visited,mp);
        return count;

    }
    void dfs(int u, int p, vector<bool>& visited, unordered_map<int,vector<pair<int,int>>>& mp){
        
        visited[u]=true;
        for(auto& vec : mp[u])
        {
            int v = vec.first;
            int c = vec.second;
            if(v!=p){
            if(c==1)
            count++;
            dfs(v,u,visited,mp);}
        }
        
    }
};