class Solution {
public:
    
    int f(int idx,vector<int>& coins,int cnt,int target,vector<vector<int>> &dp)
    {
        if(target == 0)
        {
            return 0;
        }
        
        if(idx < 0)
        {
            return INT_MAX;
        }
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        int pick=INT_MAX;
        if(target>=coins[idx])
        {
            int res=f(idx,coins,cnt+1,target-coins[idx],dp);
            if(res!=INT_MAX)
            {
                pick=1+res;
            }
        }
        int npick=f(idx-1,coins,cnt,target,dp);
        return dp[idx][target]=min(pick,npick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int cnt=0;
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=f(n-1,coins,cnt,amount,dp);
        return ans==INT_MAX?-1:ans;
        
    }
};
