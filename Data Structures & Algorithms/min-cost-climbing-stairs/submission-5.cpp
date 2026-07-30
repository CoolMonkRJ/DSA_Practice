class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int prev1= cost[1];
       int prev2= cost[0];
       int n=cost.size();
       int curr;
       for(int i=2;i<n;i++) {
        curr = cost[i] + min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
       } 
       return min(prev2,prev1);
    }
};
