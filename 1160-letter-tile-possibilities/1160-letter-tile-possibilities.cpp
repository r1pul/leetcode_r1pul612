class Solution {
public:
int n;
    void solve(string& tiles,vector<bool>& res , unordered_set<string>& result, string& curr)
    {
        result.insert(curr);
        for(int i = 0 ; i< n ; i++)
        {
            if(res[i])
            continue;

            curr.push_back(tiles[i]);
            res[i]=true;
           
            solve(tiles,res,result,curr);

            res[i]=false;
            curr.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
     n = tiles.length();
     vector<bool> res (n,false);
     unordered_set<string> result;
     string curr="";
     solve(tiles,res,result,curr);
     return result.size()-1;   
    }
    
};