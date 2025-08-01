class Solution {
public:
int t[1001];
    int solve(int n , auto& cost){
        if(n>=cost .size())
            return 0;
        if(t[n]!=-1)
            return t[n];
        int a = cost[n] + solve(n+1,cost);
        int b = cost[n] + solve(n+2,cost);
        return t[n]=min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size();
       memset(t,-1,sizeof(t));
       return  min(solve(1,cost),solve(0,cost)); 
    }
};