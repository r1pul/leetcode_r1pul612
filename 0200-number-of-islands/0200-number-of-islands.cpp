class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r=0;
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<bool>> v(n, vector<bool>(m, false));
        for(int i = 0 ; i <  n; i++)
        {
            for(int j = 0 ; j  < m;j++)
            {
                if(grid[i][j]=='1'&& !v[i][j])
                {
                    r+=1;
                    dfs(grid,i,j,v);
                    
                }
            }
        }
        return r;
    }
    void dfs(vector<vector<char>>& grid, int i , int j , vector<vector<bool>>& v)
    {
        if(i < 0 || i >= grid.size()||j<0||j>=grid[0].size()|| grid[i][j]=='0' || v[i][j])
        return;
        v[i][j]=true;
        dfs(grid,i,j+1,v);
        dfs(grid,i,j-1,v);
        dfs(grid,i+1,j,v);
        dfs(grid,i-1,j,v);
    }
};