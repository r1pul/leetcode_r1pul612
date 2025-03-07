class Solution {
public:
    string minWindow(string s, string t) {
        int n= s.length();
        int j = 0, i = 0 ; 
        if(t.length()>n)
        return "";
        int rc=t.length(), s_i = 0 , mw = INT_MAX;

        unordered_map<char,int> mp;
        for(auto& ch : t)
        mp[ch]++;

        while(j<n)
        {
            char curr = s[j];
            if(mp[curr] > 0)
            rc--;

            mp[curr]--;
            while(rc==0)
            {
                if(mw > j-i+1)
                {
                    mw=j-i+1;
                    s_i= i ;
                }
                char ch_i = s[i];
                mp[ch_i]++;
                if(mp[ch_i]>0)
                rc++;

                i++;
            }
            j++;

        }
        return mw == INT_MAX ? "" : s.substr(s_i,mw);

    }
};