class Solution {
public:
    int beststart(string &word, int n){
        int i = 0;
        int j = 1;
        while(j < n){
            int k = 0;
            while(j+k  <  n && word[i+k]==word[j+k]){
                k++;
            }
            if(j+k<n && word[j+k]>word[i+k]){
                i=j;
                j=j+1;
            }else
            j=j+k+1;
        }
        return i;
    }
    string answerString(string word, int numFriends) {
       int n = word.length();
       string res;
       int i = beststart(word,n);
       if(numFriends==1)
        return word;

       int larg = n-(numFriends -1);
       int take = min(larg,n-i);
       return word.substr(i,take);
    }
};