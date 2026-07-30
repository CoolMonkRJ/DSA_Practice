class Solution {
public:
int sum=0;
    bool canJump(vector<int>& nums) {
        if(nums[nums.size()-1]>0)
        return false;
        else
        {
        for(int i=0;i<nums.size(); i++) {
            sum+=nums[i];
            if(sum==nums.size()-1){
                return true;
            }

            i+=nums[i];
        }
        }
    }
};
