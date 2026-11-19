class Solution {
public:
    bool f(int i,int j,int k,string s1,string s2,string s3,vector<vector<vector<int>>>& dp)
    {
        if(k==s3.size())
            return true;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        bool b1=false;
        bool b2=false;
        if(i<s1.size() && s1[i]==s3[k])
            b1=f(i+1,j,k+1,s1,s2,s3,dp);
        if(j<s2.size() && s2[j]==s3[k])
            b2=f(i,j+1,k+1,s1,s2,s3,dp);
        return dp[i][j][k]=b1||b2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<string> res;
        if(s1.size()+s2.size()!=s3.size())
            return false;
        vector<vector<vector<int>>> dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return f(0,0,0,s1,s2,s3,dp);
        
    }
};
