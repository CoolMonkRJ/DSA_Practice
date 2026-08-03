class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        for(int i=0;i<nums.size();i++) {
             while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();          // Remove indices that are outside the current window.
        }
         while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();          //Remove all smaller elements from the BACK.
            }
          dq.push_back(i);  //Insert current index.

           if (i >= k - 1) {
                ans.push_back(nums[dq.front()]); //maxis always on front
                }
        }
        return ans;
    }
};
