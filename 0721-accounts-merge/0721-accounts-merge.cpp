class dsu{
    public:
    vector<int>parent;
    vector<int>rank;
    dsu(int n){
        parent.resize(n);
        rank.resize(n,0);
        
        for(int  i = 0 ; i < n ; i++){
            parent[i]=i;
            
        }
    }
    int find(int x)
    {
        if(parent[x] == x)
        return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x , int  y )
    {
        int x_p = find(x);
        int y_p  = find(y);
        if(x_p == y_p)
        return;
        if(rank[x_p]< rank[y_p]){
            parent[x_p] = y_p;
            
        }
        else if(rank[x_p]>rank[y_p]){
            parent[y_p]= x_p;
        }
        else
        parent[x_p]=y_p;
        rank[y_p]++;


    }
};
class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       int n  = accounts.size();
       dsu dsu(n);
       unordered_map<string, int> mp;
       for(int i = 0 ; i < n ; i++){
        for(int  j= 1 ; j< accounts[i].size() ; j++ ){
            string m = accounts[i][j];
            if(mp.find(m)==mp.end()){
                mp[m]=i;
            }
            else
            dsu.Union(i,mp[m]);
        }
       }
      unordered_map<int, set<string>> mm;
        for (auto& vec : mp) {
            string m = vec.first;
            int node = dsu.find(vec.second);
            mm[node].insert(m);
        }
       vector<vector<string>>ans;
       for (auto& it : mm) {
            int i = it.first;
            vector<string> temp;
            temp.push_back(accounts[i][0]); 
            temp.insert(temp.end(), it.second.begin(), it.second.end()); 
            ans.push_back(temp);
        }
        
        return ans;
    }
};