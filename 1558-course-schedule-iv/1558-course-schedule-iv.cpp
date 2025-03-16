class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        vector<int> indgree(numCourses,0);
        for(auto &vec : prerequisites){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            indgree[v]++;

        }
        queue<int> que;
        for(int i = 0 ; i < numCourses ; i++){
            if(indgree[i]==0)
            que.push(i);
        }
        unordered_map<int,unordered_set<int>>mp;
        while(!que.empty()){
            int n = que.front();
            que.pop();
            for(auto &v : adj[n]){
                mp[v].insert(n);
                for(auto &u : mp[n])
                mp[v].insert(u);

                indgree[v]--;
                if(!indgree[v])
                que.push(v);

            }
            
        }
        int q = queries.size();
        vector<bool>res(q,false);
        for(int i = 0 ; i < q; i++){
            int u = queries[i][0];
            int v = queries[i][1];
            bool isreach = mp[v].contains(u);
            res[i]=isreach;

        }
        return res;

    }
};