class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int total = 0;
        for (int x : nums)
            total += x;

        // Impossible cases
        if (abs(target) > total)
            return 0;

        if ((total + target) % 2 != 0)
            return 0;

        int req = (total + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(req + 1, 0));

        // Base cases
        if (nums[0] == 0)
            dp[0][0] = 2;          // +0 and -0
        else
            dp[0][0] = 1;          // Don't take

        if (nums[0] != 0 && nums[0] <= req)
            dp[0][nums[0]] = 1;    // Take first element

        // Fill DP table
        for (int i = 1; i < n; i++) {

            for (int sum = 0; sum <= req; sum++) {

                int notTake = dp[i - 1][sum];

                int take = 0;
                if (nums[i] <= sum)
                    take = dp[i - 1][sum - nums[i]];

                dp[i][sum] = take + notTake;
            }
        }

        return dp[n - 1][req];
    }
};