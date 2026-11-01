class Solution {
public:
    int f(int i, int j, string &text1, string &text2,vector<vector<int>>&dp)
{
    if(i == text1.size() || j == text2.size())
        return 0;


    if(dp[j][i]!=-1)
        return dp[j][i];
    if(text1[i] == text2[j])
    {
        return dp[j][i]=1 + f(i+1, j+1, text1, text2,dp);
    }

    return dp[j][i]=max(
        f(i+1, j, text1, text2,dp),
        f(i, j+1, text1, text2,dp)
    );
}
    int longestCommonSubsequence(string text1, string text2) {
       vector<vector<int>>dp(text2.size(),vector<int>(text1.size(),-1));
        return f(0,0,text1,text2,dp);
        
    }
};
