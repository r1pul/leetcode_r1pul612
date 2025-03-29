class Solution {
public:
    typedef pair<long long,int> P;
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<P>> mp;
        for(auto & vec : roads){
            int u = vec[0] ;
            int v = vec[1] ;
            int t = vec[2] ;
            mp[u].push_back({v,t});
            mp[v].push_back({u,t});

        }
        vector<long long > res(n , LLONG_MAX);
        vector<int> path(n, 0);
        res[0]=0;
        path[0]=1;
        priority_queue<P,vector<P>,greater<P>> p;
        p.push({0,0});
        while(!p.empty()){
            long long ct = p.top().first;
            int cn = p.top().second;
            p.pop();
            for(auto &vec : mp[cn]){
                int nr = vec.first;
                int rt = vec.second;
                if(ct + rt   < res[nr]){
                    res[nr]  = ct+rt;
                    p.push({res[nr],nr});
                    path[nr]  = path[cn];

                }
                else if (ct + rt == res[nr]){
                    path[nr] = (path[nr]  + path[cn])%M;
                }
            }
        }
        return path[n-1]; 
    }
};