class Solution {
public:

        int recu(int i , vector<int>&dp , vector<int>&cost){
            if(i>=cost.size()){
                return 0;
            }
            if(dp[i]!=-1){
                return dp[i];
            }
            return dp[i]= cost[i] + min(recu(i+1,dp,cost),recu(i+2,dp,cost));

        }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
     vector<int> dp(n,-1);
     return min(recu(0,dp,cost),recu(1,dp,cost));   
    }
};
