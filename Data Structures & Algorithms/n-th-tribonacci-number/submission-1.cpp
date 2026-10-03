class Solution {
public:
    int tribonacci1(int n,vector<int>&dp) {
        if(n<=1)
            return n;
        if(n==2)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=tribonacci1(n-3,dp)+tribonacci1(n-2,dp)+tribonacci1(n-1,dp);
        
    }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return tribonacci1(n,dp);
        
    }
};