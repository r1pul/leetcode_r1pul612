class dsu{
    public:
    vector<int>parent;
    vector<int>size;
    dsu(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0 ;  i< n ;  i++){
         parent[i]=i;
         
         }
    }
    int find(int x){
        if(parent[x]==x)
        return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x ,  int y){
        int x_p = find(x);
        int y_p = find(y);
        if(x_p==y_p)
        return;

        if(size[x_p]>size[y_p]){
            parent[y_p]=x_p;
            size[x_p]+=size[y_p];
        }
        else{
            parent[x_p]=y_p;
            size[y_p]+=size[x_p];

        }
        
        }
    int getsize(int x){
        return size[find(x)];
    }
};
class Solution {
public:
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int tc = n*n;
        dsu dsu(tc);
        int maxarea = 0; 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ;j++){
                if(grid[i][j]==1){
                    int idx = i*n+j;
                    for(auto& d : dir){
                        int u = i+d[0];
                        int v = j+d[1];
                        int idx_ = u*n+v;

                        if(u>=0 && u<n && v>=0 && v<n && grid[u][v]==1)
                        dsu.Union(idx,idx_);
                    }
                }
            }
        }
        for(int i = 0 ; i<tc ; i++){
            if(grid[i/n][i%n]==1)
                maxarea=max(maxarea,dsu.getsize(i));
        }
        for(int i=0 ; i<n ; i++){
            for(int j = 0 ; j< n ; j++){
                if(grid[i][j]==0){
                unordered_set<int>mp;
                for(auto& d : dir){
                    int u = i+d[0];
                    int v = j + d[1];
                    int idx = u * n + v;
                    if(u>=0 && u<n && v>=0 && v<n && grid[u][v]==1)
                    mp.insert(dsu.find(idx));

                }
                int ns=1;

                for(auto& vec : mp){
                    ns+=dsu.getsize(vec);
                    
                }
                maxarea = max(maxarea,ns);
                }
            }
        }
        return maxarea;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();