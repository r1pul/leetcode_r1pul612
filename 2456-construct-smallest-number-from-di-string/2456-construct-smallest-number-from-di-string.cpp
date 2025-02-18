class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string num = "";
        for (int i = 1; i <= n + 1; i++) {
            num.push_back(i + '0');
        }
        while (!pat(pattern, num)) {
            next_permutation(num.begin(), num.end());
        }
        return num;
    }
    bool pat(string& pattern, string& num) {
        int n = pattern.length();
        for (int i = 0; i < n; i++) {
            if (pattern[i] == 'I' && num[i] > num[i + 1] || pattern[i] == 'D' &&
                num[i] < num[i + 1])
                return false;
        }
        return true;
    }
};