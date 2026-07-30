class Solution {
public:

    int climb(int n, vector<int>& dp) {

        // Invalid state
        if (n < 0)
            return 0;

        // Base case
        if (n == 0)
            return 1;

        // Already computed
        if (dp[n] != -1)
            return dp[n];

        // Compute, store, and return
        dp[n] = climb(n - 1, dp) + climb(n - 2, dp);

        return dp[n];
    }

    int climbStairs(int n) {

        vector<int> dp(n + 1, -1);

        return climb(n, dp);
    }
};