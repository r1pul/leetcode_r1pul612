class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!visited[i][j]){
                   if(dfs(visited,grid,i,j,-1,-1))
                   return true;
                }
            }
        }
        return false;


    }
    bool dfs(auto& visited,auto& grid, int i, int j , int pi,int pj){
        int n = grid.size();
        int m =grid[0].size();

        if(i<0|| i>n || j<0 || j>m)
        return false;

        if(pi!=-1 && pj!=-1 && grid[i][j] != grid[pi][pj])
            return false;
        
        if(visited[i][j])
            return true;
        
        visited[i][j]=true;

        if(i-1>=0 && i-1 != pi)
            if(dfs(visited,grid,i-1,j,i,j))
                return true;
        if(i+1<n && i+1!=pi)
            if(dfs(visited,grid,i+1,j,i,j))
                return true;
        if(j-1>=0 && j-1!=pj)
            if(dfs(visited,grid,i,j-1,i,j))
                return true;
        if(j+1<m && j+1!=pj)
            if(dfs(visited,grid,i,j+1,i,j))
                return true;

        return false;
    }
};