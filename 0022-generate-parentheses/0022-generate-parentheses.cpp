class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr, n);
        return result;
    }
    void solve(string& curr, int n) {
        if (curr.length() == 2 * n) {
            if (isvalid(curr))
                result.push_back(curr);

            return;
        }
        curr.push_back('(');
        solve(curr, n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();
    }
    bool isvalid(string& curr) {
        int c = 0;
        for (auto& ch : curr) {
            if (ch == '(')
                c++;
            else
                c--;
            if (c < 0)
                return false;
        }
        return c == 0;
    }
};