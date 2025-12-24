class Solution {
public:
    int N , res = -1;
    vector<bool>inR;
    vector<bool>visited;
    vector<int>count;
    int longestCycle(vector<int>& edges) {
        N = edges.size();
        inR.resize(N,false);
        visited.resize(N,false);
        count.resize(N,1);
        for(int i = 0 ;  i < N ; i++){
            if(!visited[i])
            dfs(i,edges);
        }
        return res;

    }
    void dfs(int u , auto& edges){
        if(u != -1){
            visited[u] = true;
            inR[u] = true;
            int v = edges[u];
            if(v != -1 && !visited[v]){
                count[v] = count[u] + 1;
                dfs(v,edges);
            }
            else if(v != -1 && inR[v]==true){
                res = max(res, count[u] - count[v] + 1);
            }
            
            
            inR[u] = false;
        }
        
    }
};