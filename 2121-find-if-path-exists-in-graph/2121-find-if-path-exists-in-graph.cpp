class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        for(auto& vec : edges){
            int u = vec[0];
            int v = vec[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool>visited(n,false);
        return dfs(mp,visited,source,destination);

    }
    bool dfs(unordered_map<int,vector<int>>& mp , vector<bool>& visited, int u , int v){
        if(u==v)
        return true;
        visited[u]=true;

        for(auto& vec : mp[u]){
            if(!visited[vec])
            if(dfs(mp,visited,vec,v))
                return true;
            
        }
        return false;
    }

};