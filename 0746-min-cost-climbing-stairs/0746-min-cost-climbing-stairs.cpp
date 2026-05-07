class Solution {
public:
    vector<int>dp;
    int solve(auto & cost , int n){
        if( n < 0)
            return 0;

        if(n == 0 || n == 1)
            return cost[n];
        
        if(dp[n] != -1)
            return dp[n];

        return dp[n] = cost[n] + min(solve(cost,n-1),solve(cost,n-2));

        
    }
    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size();
       dp.resize(n+1, -1);
       
       return  min(solve(cost,n-1),solve(cost,n-2));

    }
    
};