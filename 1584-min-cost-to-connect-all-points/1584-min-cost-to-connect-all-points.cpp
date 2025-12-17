class Solution {
public:
    vector<int>parent;
    vector<int>size;
    int find(int x){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        x = find(x);
        y = find(y);

        if( x != y){
            if( x < y)
                swap(x,y);
            
            parent[y] = x;
            size[x] += size[y];
                
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        parent.resize(v);
        for(int i = 0 ;  i < v ; i++)
            parent[i] = i;
        size.resize(v,1);
        vector<pair<int,pair<int,int>>>mp;
        for(int i = 0 ;  i < v ;i++){
            for(int j = i + 1 ; j < v ; j++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];
            

            int d = abs(x1-x2) + abs(y1 - y2);


            mp.push_back({d,{i,j}});
            }
        }
        sort(mp.begin(),mp.end());
        return kruskal(mp);

    }
    int kruskal(auto& mp){
        int sum = 0;
        for(auto& vec : mp){
            int wt = vec.first;
            auto [u,v] = vec.second;

            int x = find(u);
            int y = find(v);

            if(x != y){
                Union(x,y);
                sum += wt;
            }
        }
        return sum;
    }
};