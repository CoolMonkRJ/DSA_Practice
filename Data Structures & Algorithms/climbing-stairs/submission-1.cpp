class Solution {
public:

    void climb(int n , int &ans) {
        if(n==0){
            ans+=1;
            return;
        }
        if(n<0){
            return;
        }
        
        climb(n-1,ans);
        climb(n-2,ans);
    }
    int climbStairs(int n) {
        int ans =0;
        climb(n,ans);
        return ans;
        
    }
};
