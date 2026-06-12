class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=INT_MIN;
        int l=0;
        int r=1;
        
        while(r<n && l<r)
        {
            if(prices[l]<=prices[r])
            {
                int profit=prices[r]-prices[l];
                maxProfit=max(maxProfit,profit);
                r++;
            }
            else{
                l=r;
                r++;
            }
        }
        return maxProfit==INT_MIN ? 0 : maxProfit;
        
    }
};
