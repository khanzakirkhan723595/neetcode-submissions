class Solution {
public:
    int f(int idx,vector<int>& cost,vector<int>&dp)
    {
        if(idx<0)
            return 0;
        if(idx==0)
            return cost[idx];
        if(dp[idx]!=-1)
            return dp[idx];
        int minc=cost[idx];
        int fs=0;
        if(idx>=1)
            fs+=f(idx-1,cost,dp);
        int ss=0;
        if(idx>=2)
            ss+=f(idx-2,cost,dp);
        return dp[idx]=minc+min(fs,ss);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(f(cost.size()-1,cost,dp),f(cost.size()-2,cost,dp));
        
    }
};
