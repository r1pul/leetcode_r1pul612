class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp ;
        for(auto &vec:edges){
            int u = vec[0];
            int v = vec[1];
            mp[u].push_back(v);
            mp[v].push_back(u);

        }
        int res=0;
        vector<bool>visited(n,false);
        for(int i = 0 ; i < n ; i++)
        {
            if(visited[i]==true)
            continue;

            int u = 0 , v = 0;
            bfs(mp,visited,u,v,i);
            if((u*(u-1))==v)
            res++;
        }
        return res;




    }
    void bfs(unordered_map<int,vector<int>> &mp , vector<bool>& visited , int &u , int &v, int i){
        queue<int>que;
        que.push(i);
        visited[i]=true;

        
        while(!que.empty())
        {
            int c = que.front();
            que.pop();
            u++;
            v += mp[c].size();
            for(auto &vec : mp[c])
            if(visited[vec]!=true)
            bfs(mp,visited,u,v,vec);

        }
        
        


    }       
};