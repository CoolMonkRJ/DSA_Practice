class Solution {
public:
    void sum(int i ,int target,vector<int>&nums, vector<vector<int>>&ans , vector<int>&temp) {
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0) {
            return;
        }
        if(i>=nums.size()) {
            return;
        }
        temp.push_back(nums[i]);
        sum(i,target-nums[i],nums,ans,temp);
        temp.pop_back();
        sum(i+1,target,nums,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sum(0,target,nums,ans,temp);
        return ans;
    }
};
