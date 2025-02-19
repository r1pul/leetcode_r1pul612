class Solution {
public:
    string getHappyString(int n, int k) {
        string res = "";
        string ch = "";
        int count = 0;

        solve(ch, res, n, k, count);
        

        return res;
    }
    void solve(string& ch, string& res, int n, int k, int& count) {
        if (ch.size() == n) {
            count++;
            if (count == k) {
                res = ch;
            }
            return;
        }
        for (char i = 'a'; i <= 'c'; i++) {
            if (!ch.empty() && ch.back() == i)
                continue;
            ch.push_back(i);
            solve(ch, res, n, k, count);
            if(!res.empty())
            return;
            ch.pop_back();
        }
    }
};