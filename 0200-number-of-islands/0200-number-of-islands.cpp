class Solution {
public:
int n, m;
    void dfs(int u , int v , auto& visited, auto& grid){
        if( u < 0 || u>=n || v<0 || v>=m || grid[u][v]=='0' || visited[u][v] )
            return;
        visited[u][v]=true;
        dfs(u+1,v, visited, grid);
        dfs(u-1,v,visited, grid);
        dfs(u,v+1,visited, grid);
        dfs(u,v-1,visited, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = 0;
        n = grid.size();
        m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i = 0 ; i  < n ; i++){
            for(int j = 0 ;  j < m ; j++){
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    r++;
                    dfs(i,j,visited,grid);
                }
            }
        }
    return r;
    }
};