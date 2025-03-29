class Solution {
public:
    void DFS(unordered_map<int,vector<int>>& mp,int i , vector<bool>& visited)
    {
        visited[i]=true;
        for(int &v : mp[i])
        {
            if(!visited[v])
            {
                DFS(mp,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>mp;
        vector<bool>visited(isConnected.size(),false);
        int count = 0;
        for(int i = 0 ; i < isConnected.size();i++ )
        {
            for(int j = 0 ; j < isConnected.size();j++)
            {
                if(isConnected[i][j]==1)
                {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        for(int i = 0 ; i < isConnected.size();i++)
        {
            if(!visited[i])
            {
                DFS(mp,i,visited);
                count++;
            }
        }
        return count;
    }
};