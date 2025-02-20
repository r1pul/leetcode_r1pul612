class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res ="";
        int n = nums.size();
        for(int i = 0 ; i< n;i++)
        {
            char ch = nums[i][i];
            if(ch=='0')
            res+='1';
            else
            res+='0';
        }
        return res;

    }
};