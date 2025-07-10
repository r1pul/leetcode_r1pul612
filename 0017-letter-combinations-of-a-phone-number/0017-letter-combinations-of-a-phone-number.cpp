class Solution {
public: 
    vector<string>res;
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        if(digits.empty())
        return res;
        string temp = "";
        solve(0,temp,mp,digits);
        return res;
    }
    
    void solve(int idx, string temp, unordered_map<char,string>& mp, string digits){
        if(idx>=digits.size())
        {
            res.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for(int i = 0 ; i < str.size(); i++){
            temp.push_back(str[i]);
            solve(idx+1,temp,mp,digits);
            temp.pop_back();
        }
    }

};