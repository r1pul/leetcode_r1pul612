class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int res=0;
        vector<vector<int>> mat(r * 3, vector<int>(c * 3, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '/') {
                    mat[i * 3][j * 3 + 2] = 1;
                    mat[i * 3 + 1][j * 3 + 1] = 1;
                    mat[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    mat[i * 3][j * 3] = 1;
                    mat[i * 3 + 1][j * 3 + 1] = 1;
                    mat[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    DFS(mat, i, j);
                    res += 1;
                }
            }
        }
        return res;
    }
    void DFS(vector<vector<int>>& mat, int i, int j) {
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() ||
            mat[i][j] == 1)
            return;

        mat[i][j] = 1;
        DFS(mat, i + 1, j);
        DFS(mat, i - 1, j);
        DFS(mat, i, j + 1);
        DFS(mat, i, j - 1);
    }
};