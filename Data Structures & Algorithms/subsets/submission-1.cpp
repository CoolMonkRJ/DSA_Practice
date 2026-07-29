class Solution {
public:

    void subset (int i,vector<int>&nums,vector<int>&temp,vector<vector<int>>&answer){
        if(i>=nums.size()) {
            answer.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        subset(i+1,nums,temp,answer);
        temp.pop_back();
        subset(i+1,nums,temp,answer);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> answer;
        subset(0,nums,temp,answer);
        return answer;
    }
};
