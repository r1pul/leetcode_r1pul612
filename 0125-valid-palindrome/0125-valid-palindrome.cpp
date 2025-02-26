class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for (char vec : s)
            if (isalnum(vec))
                res += tolower(vec);

        int l = 0;
        int r = res.size() - 1;

        while (l < r) {
            if (res[l] != res[r])
                return false;

            l++;
            r--;
        }
        return true;
    }
};