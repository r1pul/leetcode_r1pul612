class Solution {
public:
    void preprocess(int n, vector<vector<bool>>& grid,unordered_map<int, vector<int>>& adj ){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i!=j){
                    vector<bool>visited(n,false);
                    if(dfs(adj,i,j,visited)){
                        grid[i][j]=true;
                    }
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (auto& vec : prerequisites) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
        }
        vector<vector<bool>> grid(numCourses,vector<bool>(numCourses,false));
        preprocess(numCourses,grid,adj);
        int q = queries.size();
        vector<bool> res(q);
        for (int i = 0; i < q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            
            res[i] = grid[u][v];
        }
        return res;
    }
    bool dfs(unordered_map<int, vector<int>>& adj, int u, int v,
             vector<bool>& visited) {
        visited[u] = true;
        if(u==v)
        return true;
        bool isreach = false;
        for (auto& vec : adj[u]) {
            if (!visited[vec]) {
                isreach = isreach || dfs(adj, vec, v, visited);
            }
           
        }
         return isreach;
    }
};