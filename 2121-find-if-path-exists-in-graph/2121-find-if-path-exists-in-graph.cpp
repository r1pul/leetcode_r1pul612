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
        queue<int>q;
        q.push(source);
        visited[source]=1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr==destination)
            return true;
            
            for(auto& vec : mp[curr]){
                if(!visited[vec]){
                 visited[vec]=1;
                 q.push(vec);
                 }
            }
        }
    return false;
    }

};