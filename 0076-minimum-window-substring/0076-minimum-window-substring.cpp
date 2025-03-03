class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> mp;
        if (t.size() > n)
            return "";

        for (auto& ch : t)
            mp[ch]++;

        int reqc = t.size();
        int i = 0, j = 0;
        int wsize = INT_MAX;
        int s_i = 0;

        while (j < n) {
            char ch = s[j];
            if (mp[ch] > 0)
                reqc--;
            mp[ch]--;

            while (reqc == 0) {
                int cc = j - i + 1;

                if (wsize > cc) {
                    wsize = cc;
                    s_i = i;
                }
                
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    reqc++;

                i++;
            }
            j++;
        }
        return wsize == INT_MAX ? "" : s.substr(s_i, wsize);
    }
};