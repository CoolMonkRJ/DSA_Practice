class Solution {
public:

        int recu(int i , vector<int>&dp , vector<int>&cost){
        dp[0] = cost[0];
        dp[1] = cost[1];
            int n= cost.size();
            for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
            }

            return min(dp[n-1], dp[n-2]);

        }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
     vector<int> dp(n,0);
     return min(recu(0,dp,cost),recu(1,dp,cost));   
    }
};
