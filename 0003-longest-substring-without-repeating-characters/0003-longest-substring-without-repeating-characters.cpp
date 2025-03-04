class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, n = s.length();
        if(n==0)
            return 0;
        map <char, bool> exists;
        int p1,p2;
        for ( p2 = 0, p1 = 0; p2 < n;) {
            while (p2 < n) {
                if (!exists[s[p2]]) {
                    exists[s[p2]] = true;
                    p2++;
                } else {
                    ans = max(ans, p2 - p1);
                    break;
                }
            }
            if (p1 < n) { 
                exists[s[p1]] = false;
                ++p1;
            }
            
        }
        
        return max(ans, p2 - p1+1);
    }
};