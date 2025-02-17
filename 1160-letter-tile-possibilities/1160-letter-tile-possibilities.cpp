class Solution {
public:
 int count;
    int numTilePossibilities(string tiles) {
       count=0;
       vector<int>vec(26,0);
       for(auto& ch : tiles)
       {
        vec[ch-'A']++;

       }
       solve(vec); 
       return count-1;
    }
    void solve(vector<int>& vec)
    {
        count++;
        for(int i = 0  ; i< 26 ; i++)
        {
            if(vec[i]==0)
            continue;
            vec[i]--;
            solve(vec);
            vec[i]++;
        }
    }
};