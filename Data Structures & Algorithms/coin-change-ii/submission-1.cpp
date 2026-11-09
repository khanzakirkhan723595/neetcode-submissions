class Solution {
public:
    int f(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 1;

        if (i == coins.size()) return 0;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int p = 0;

        if (coins[i] <= amount)
            p = f(i, amount - coins[i], coins, dp);

        int np = f(i + 1, amount, coins, dp);

        return dp[i][amount] = p + np;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        return f(0, amount, coins, dp);
    }
};