class Solution {
public:
    
    int f(int idx, vector<int>& nums,int prev,vector<vector<int>>& dp)
    {
        if(idx==nums.size())
            return 0;
        
        if(dp[idx][prev+1]!=-1)
            return dp[idx][prev+1];

        int npick=f(idx+1,nums,prev,dp);
        int pick=0;
        if(prev==-1 || nums[idx]>nums[prev])
            pick=1+f(idx+1,nums,idx,dp);
        
        
        return dp[idx][prev+1]=max(pick,npick);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int a=f(0,nums,-1,dp);
        return a;

        
    }
};
