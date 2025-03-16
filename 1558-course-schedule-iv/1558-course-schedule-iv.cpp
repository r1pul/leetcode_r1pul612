class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (auto& vec : prerequisites) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
        }
        int q = queries.size();
        vector<bool> res(q);
        for (int i = 0; i < q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            vector<bool> visited(numCourses, false);
            res[i] = dfs(adj, u, v, visited);
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