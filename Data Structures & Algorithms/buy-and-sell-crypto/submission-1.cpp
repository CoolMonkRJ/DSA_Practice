class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int profit = 0;
        int l=0;
        int r= l+1;
        while(r<prices.size()) {
            if(prices[l]>prices[r])
            {
                l++;
            }
            profit= prices[r]-prices[l];
            r++;
            maxProfit= max(maxProfit,profit);
        }
        return maxProfit;
        
    }
};
