class Solution {
public:
    int numberOfSubstrings(string s) {
      unordered_map<char, int> mp;
      int n = s.size();
      int i = 0, j = 0 , result = 0;
      while(j < n){
        char ch = s[j];
        mp[ch]++;
        while(mp['a'] > 0 && mp['b']>0 && mp['c']>0 )
        {
            result += (n-j);
            mp[s[i]]--;
            i++;
        }
        j++;
      }
      return result;  
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c'; // Return value is unused
}();