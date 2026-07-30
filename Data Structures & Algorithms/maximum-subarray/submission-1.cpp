class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=0;
        int sum =0;
        int l=0;
        int r=1;
        if(nums.size()<2)
        return nums[0];
        else{
        while(r<nums.size()) {
            if(sum+nums[r] < 0){
            l=r;
            sum=0;
            r+=1;
            }
            else {
            sum+=nums[r];
            r++;
            }
            maxSum= max(sum,maxSum);
        }
        }
        return maxSum;
    }
};
