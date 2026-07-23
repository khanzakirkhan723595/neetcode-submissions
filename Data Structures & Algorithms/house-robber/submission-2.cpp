class Solution {
public:
    int f(int idx,vector<int>& nums,vector<int> &dp)
    {
        if(idx<0)
            return 0;
        if(idx==0)
            return nums[idx];
        if(dp[idx]!=-1)
            return dp[idx];
        int take=nums[idx]+f(idx-2,nums,dp);
        int ntake=0+f(idx-1,nums,dp);
        return dp[idx]=max(take,ntake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums.size()-1,nums,dp);
        
    }
};
