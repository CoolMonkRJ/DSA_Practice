class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // If there are 0 or 1 intervals, nothing needs to be merged.
        if(intervals.size() <= 1)
            return intervals;

        // Step 1:
        // Sort intervals based on their starting time.
        // Example:
        // Before: [8,10] [1,3] [2,6]
        // After : [1,3] [2,6] [8,10]
        //
        // Why?
        // So every interval that can overlap with the current one
        // will appear immediately after it.
        sort(intervals.begin(), intervals.end());

        // This vector will store the final merged intervals.
        vector<vector<int>> ans;

        // Step 2:
        // Put the first interval into the answer.
        // We have nothing to compare it with yet.
        ans.push_back(intervals[0]);

        // Step 3:
        // Start checking from the second interval.
        for(int i = 1; i < intervals.size(); i++) {

            // Current interval
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Last merged interval stored in answer
            int lastEnd = ans.back()[1];

            // -------------------------------
            // CASE 1 : Overlapping intervals
            if(start <= lastEnd) {

                // We DON'T change the start because
                // after sorting, the previous interval
                // always starts earlier.
                ans.back()[1] = max(lastEnd, end);
            }

            // --------------------------------
            // CASE 2 : No overlap
            // --------------------------------
            //
            else {

                // Store it as a new interval.
                ans.push_back(intervals[i]);
            }
        }

        // Return all merged intervals.
        return ans;
    }
};