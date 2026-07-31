class Solution {
public:
    int f(int idx,string s,vector<int> &dp)
    {
        if(idx==s.size())
        {
            return 1;
        }
        if(s[idx]=='0')
        {
            return 0;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        //pick one
        int po=f(idx+1,s,dp);
        //pick two
        int pt=0;
        if(idx+1<s.size())
        {
            int num=(s[idx]-'0')*10 + s[idx+1]-'0';
            if(num>=10 && num<=26)
            {
                pt+=f(idx+2,s,dp);
            }
        }
        return dp[idx]=po+pt;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return f(0,s,dp);
        
    }
};
