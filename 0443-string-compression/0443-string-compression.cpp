class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0 ;
        int i =0 ;
        while(i < n)
        {
            char curr = chars[i];
            int count = 0;
             while (i < n && chars[i]==curr)
             { 
                count++;
                i++;

             }
             chars[index]=curr;
             index++;
             if(count > 1)
             { 
                string count_ch = to_string(count);
                for(auto &ch : count_ch)
                {  

                    chars[index] =ch;
                    index++;
                }
             }
        }
        return index;
    }
};