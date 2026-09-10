class Solution {
public:
    int f(int idx, int tsum, vector<int>& nums, int n, int target,
          vector<vector<int>>& dp)
    {
        if(idx == n)
        {
            return tsum == target;
        }

        if(dp[idx][tsum + 1000] != -1)
            return dp[idx][tsum + 1000];

        // Take +
        int plusSum = tsum + nums[idx];
        int a = f(idx + 1, plusSum, nums, n, target, dp);

        // Take -
        int minusSum = tsum - nums[idx];
        int s = f(idx + 1, minusSum, nums, n, target, dp);

        return dp[idx][tsum + 1000] = a + s;
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2001, -1));

        return f(0, 0, nums, n, target, dp);
    }
};