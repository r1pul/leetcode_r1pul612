class Solution {
public:
    int n  ,m;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m=image[0].size();
        vector<vector<int>>res = image;
        int ic  = image[sr][sc];
        dfs(image,res,sr,sc,color,ic);
        return res;
    }
    void dfs( auto& image, auto& res, int i, int j , int c , int ic){
        if(i<0 || i>=n || j < 0 || j>=m || image[i][j]!=ic || res[i][j]==c)
            return;
        res[i][j]=c;
        dfs(image, res,i+1,j,c,ic);
        dfs(image, res, i-1,j,c,ic);
        dfs(image, res, i , j+1,c,ic);
        dfs(image,res,i,j-1,c,ic);
    }
};