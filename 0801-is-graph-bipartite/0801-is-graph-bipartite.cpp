class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i =0; i < graph.size();i++)
        {
            if(color[i]==-1)
            {
                if(checkdfs(graph,i,color,1)==false)
                return false;
            }
        }
        return true;
    }
    bool checkdfs(vector<vector<int>>& graph,int curr ,vector<int>& color,int currcolor )
    {
        color[curr]=currcolor;
        for(auto& v : graph[curr])
        {
            if(color[v]==color[curr])
            return false;
            if(color[v]==-1)
            {
                int colorofv = 1 - currcolor;
                if(checkdfs(graph,v,color,colorofv)==false)
                return false;
            }
        }
        return true;
    }
};