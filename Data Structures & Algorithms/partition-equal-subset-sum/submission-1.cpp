class Solution {
public:
    bool f(int idx,vector<int>& nums,int sum,int tsum,vector<vector<int>>& dp)
    {
        if(idx==nums.size()-1)
        {
            if(sum==tsum-sum)
                return true;
            else
                return false;

        }
        if(dp[idx][sum]!=-1)
            return dp[idx][sum];
        sum+=nums[idx];
        bool pick=f(idx+1,nums,sum,tsum,dp);
        sum-=nums[idx];
        bool npick=f(idx+1,nums,sum,tsum,dp);
        return dp[idx][sum]= (pick || npick);

        
    }
    bool canPartition(vector<int>& nums) {
        
        int tsum=0;
        for(int i=0;i<nums.size();i++)
            tsum+=nums[i];
        vector<vector<int>> dp(nums.size()+1,vector<int>(tsum,-1));
        return f(0,nums,0,tsum,dp);
        
    }
};
