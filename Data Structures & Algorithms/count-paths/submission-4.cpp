class Solution {
public:
    int f(int i,int j,int m,int n,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=0;
        if(i>0)
            up+=f(i-1,j,m,n,dp);
        int left=0;
        if(j>0)
            left+=f(i,j-1,m,n,dp);
        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        //vector<vector<int>>dp(m,vector<int>(n,0));
        // f(m-1,n-1,m,n,dp);
        // if(m==1 && n==1)
        //     return 1;
        // return dp[m-1][n-1];
        vector<int>prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> curr(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    curr[j]=1;
                    continue;
                }
                int up=prev[j];
                int left=0;
                if(j>0)
                    left+=curr[j-1];
                curr[j]=up+left;


            }
            prev=curr;
        }
        return prev[n-1];

        
        
    }
};
