class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int l=i+1;
            int end=nums.size()-1;
            while(l<end)
            {
                int sum= nums[i]+nums[l]+nums[end];
                if(sum>0)
                {
                    end--;
                }
                else if(sum<0)
                {
                    l++;
                }
                else
                {
                    res.push_back({nums[i],nums[l],nums[end]});
                    l++;
                 end--;
                   //
                }
            }
        }
        
        return res;
    }
};