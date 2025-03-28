class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n =s.length();
        vector<int>t(n+1,0);
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        for(int i = n-1 ; i>=0 ; i--)
        {
            t[i]=1+t[i+1];
            for(int j = i ; j<n ; j++)
            {
                string curr = s.substr(i,j-i+1);
                if(st.count(curr))
                {
                    t[i]=min(t[i],t[j+1]);
                }
            }
        }
        return t[0];
    }
   
};