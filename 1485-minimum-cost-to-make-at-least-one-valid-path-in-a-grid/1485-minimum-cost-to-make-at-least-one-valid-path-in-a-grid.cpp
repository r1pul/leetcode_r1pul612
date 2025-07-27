class Solution {
public:
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>res(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({0,0,0});
        res[0][0]=0;
        while(!pq.empty()){
            auto curr  =pq.top();
            pq.pop();
            int cc = curr[0];
            int u = curr[1];
            int v =curr[2];
            for(int k = 0 ; k <=3; k++){
                int i = u + dir[k][0];
                int j = v + dir[k][1];


                if(i>=0 && i<n && j>=0 && j<m){
                    int d = grid[u][v];
                    int dc =( (d-1 != k) ? 1:0) ; 
                    int nc = cc + dc;
                    if(nc < res[i][j]){
                        res[i][j]=nc;
                        pq.push({nc,i,j});
                    }
                }
            }
        }
        return res[n-1][m-1];
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

