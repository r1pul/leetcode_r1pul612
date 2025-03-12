class Solution {
public:
    int longestValidParentheses(string s) {
       stack<int>st;
       int n = s.size();
       int i = 0 ;
       int maxl = 0;
       st.push(-1);
       for(int i = 0 ; i < n ; i++){
        if(s[i]=='(')
            st.push(i);
        else
        st.pop();

        if(!st.empty()){
            int l = i - st.top();
            maxl = max(maxl,l);
            }
        else
            st.push(i);
       } 
       return maxl;
    }
};
