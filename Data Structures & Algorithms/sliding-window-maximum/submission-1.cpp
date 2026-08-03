class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;

        int l = 0;
        int r = k - 1;

        while (r < nums.size()) {

            // Assume first element of window is maximum
            int maxi = nums[l];

            // Check every element in current window
            for (int i = l; i <= r; i++) {
                maxi = max(maxi, nums[i]);
            }

            ans.push_back(maxi);

            l++;
            r++;
        }

        return ans;
    }
};