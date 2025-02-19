class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> res;
        string ch = "";
        solve(ch, res, n);
        if (res.size() < k)
            return "";
        
        return res[k - 1];
    }
    void solve(string& ch, vector<string>& res, int n) {
        if ( ch.size() == n) {
            res.push_back(ch);
            return;
        }
        for (char i = 'a'; i <= 'c'; i++) {
            if (!ch.empty() &&ch.back() == i)
                continue;
            ch.push_back(i);
            solve(ch, res, n);
            ch.pop_back();
        }
    }
};