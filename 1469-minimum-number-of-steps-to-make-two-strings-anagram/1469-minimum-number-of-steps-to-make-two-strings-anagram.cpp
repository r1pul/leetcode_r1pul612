class Solution {
public:
    int minSteps(string s, string t) {
      int c[26]= {0};
      int n = s.size();
      int i = 0;
      int ans = 0 ;
      while(i < n){
        c[t[i]-'a']++;
        c[s[i]-'a']--;
        i++;
      }
      i = 0;
      while(i<26)
      {
        ans += max(0,c[i]);
        i++;
      }
      return ans;
    }
};