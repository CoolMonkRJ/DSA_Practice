class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size();
        int r=1;
        for (int l=0;l<n;l++)
        {
            if(l+r == target)
            return {l,r};
            else
            r++;
        }
    }
};
