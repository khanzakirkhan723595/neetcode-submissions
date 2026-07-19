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
        //vector<int> dp(n+1,-1);
        // int ans = f(n,dp);
        // return ans;
        int prev=1;
        int prev2=0;
        for(int i=1;i<=n;i++)
        {
            int u=prev;
            int v=0;
            if(i>1)
                v+=prev2;
            int curr=u+v;
            prev2=prev;
            prev=curr;
        }
        return prev;
        
        
    }
};
