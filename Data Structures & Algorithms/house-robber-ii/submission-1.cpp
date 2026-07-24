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
    int rob1(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums.size()-1,nums,dp);
        
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=nums.size()-1)
                temp2.push_back(nums[i]);

        }
        int ans1=rob1(temp1);
        int ans2=rob1(temp2);
        return max(ans1,ans2);
        
    }
};
