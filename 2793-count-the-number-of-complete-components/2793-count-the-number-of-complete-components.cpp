class Solution {
public:
    class DSU {
        public:
        vector<int> parrent;
        vector<int> Size;
        DSU(int n ){
            parrent.resize(n);
            Size.resize(n);
            for(int i = 0 ; i < n ;  i++)
            {
                parrent[i]=i;
                Size[i]=1;
            }

        }
        int find(int x) {
            // Path compression: make the tree flatter
            if (parrent[x] == x) {
                return x;  // Recursively find the root and update the parent
            }
            return parrent[x]=find(parrent[x]);
        }
        void Union(int x , int y)
        {
            int x_p = find(x);
            int y_p = find(y);
            if(x_p==y_p)
            return;
            if(Size[x_p] > Size[y_p]){
                parrent[y_p]=x_p;
                Size[x_p]+=Size[y_p];
            }
            else if(Size[x_p] < Size[y_p]){
                parrent[x_p]= y_p;
                Size[y_p]+=Size[x_p];
            }
            else{
            parrent[y_p]= x_p;
            Size[x_p]+=Size[y_p];
                }

        }


    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_map<int,int>mp;
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            dsu.Union(u,v);
        }
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            int root = dsu.find(u);
            mp[root]++;
        }
        int res= 0;
        for(int i = 0 ; i < n ; i++){
            if(dsu.find(i)==i)
            {
                int u = dsu.Size[i];
                int v = mp[i];
                if ((u * (u - 1)) / 2 == v)
                res++;
            }
        }
        return res;

    }
};