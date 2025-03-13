class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int j = 0;
        int maxl = 0;
        int mp[26] = {0};
        for (int i = 0; i < n; i++) {
            mp[s[i] - 'A']++;

            int maxf = *max_element(mp, mp + 26);

            while ((i - j + 1) - maxf > k) {
                mp[s[j] - 'A']--;
                j++;
            }
            maxl = max(maxl, i - j + 1);
        }
        return maxl;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c'; 
}();
