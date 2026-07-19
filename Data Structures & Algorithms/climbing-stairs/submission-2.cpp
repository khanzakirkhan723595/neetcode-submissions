class Solution {
public:
    int f(int n,vector<int> &dp)
    {
        if(n==0 || n==1)
            return 1;
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n]= f(n-2,dp)+f(n-1,dp);
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        // int ans = f(n,dp);
        // return ans;
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            int u=dp[i-1];
            int v=0;
            if(i>1)
                v+=dp[i-2];
            dp[i]=u+v;
        }
        return dp[n];
        
        
    }
};
