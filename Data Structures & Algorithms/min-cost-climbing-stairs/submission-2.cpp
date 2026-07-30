class Solution {
public:

    int solve(int start,vector<int>&cost,vector<int>&dp,int i){
        if(i==start)
            return cost[i];
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=cost[i]+min(i-2>=start?solve(start,cost,dp,i-2):INT_MAX/2,i-1>=start?solve(start,cost,dp,i-1):INT_MAX/2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1),dp2(cost.size(),-1);
        return min(min(solve(0,cost,dp,cost.size()-1),solve(1,cost,dp2,cost.size()-1)),min(solve(0,cost,dp,cost.size()-2),solve(1,cost,dp2,cost.size()-2)));
    }
};
