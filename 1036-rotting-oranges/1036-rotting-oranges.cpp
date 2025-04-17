class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        int n  = grid[0].size();
        int m = grid.size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ;  j < n ; j++){
                if(grid[i][j]==2){
                dfs(grid,i,j,2);
                }
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j  < n ; j++){
                if(grid[i][j]==1)
                return -1;
            res = max(res,grid[i][j]);
            }

        }
        return res == 0 ? 0 : res - 2;
    }
    void dfs(vector<vector<int>>& grid , int  i , int j , int t ){
        if(i < 0 || i == grid.size() || j< 0 || j == grid[0].size() || grid[i][j]==0 || (grid[i][j]<t && grid[i][j]>1))
        return;

        grid[i][j]=t;
        dfs(grid,i-1,j,t+1);
        dfs(grid,i,j-1,t+1);
        dfs(grid,i+1,j,t+1);
        dfs(grid,i,j+1,t+1);
        
    }
};