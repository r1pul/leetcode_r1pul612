class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxprice = 0;
        int s = prices.size();
        for(int i =0 ; i< s ; i++)
        {
            maxprice=max(maxprice,prices[i]-minprice);
            minprice=min(prices[i],minprice);
        }
        return maxprice;
    }
};