class Solution {
public:
    void f(string s,vector<int> &dp)
    {

        // if(idx==s.size())
        // {
        //     return 1;
        // }
        // if(s[idx]=='0')
        // {
        //     return 0;
        // }
        // if(dp[idx]!=-1)
        // {
        //     return dp[idx];
        // }
        // //pick one
        // int po=f(idx+1,s,dp);
        // //pick two
        // int pt=0;
        // if(idx+1<s.size())
        // {
        //     int num=(s[idx]-'0')*10 + s[idx+1]-'0';
        //     if(num>=10 && num<=26)
        //     {
        //         pt+=f(idx+2,s,dp);
        //     }
        // }
        // return dp[idx]=po+pt;

        //tabulation
        // One way to decode an empty string
        dp[0] = 1;

        // The first digit cannot be 0
        dp[1] = (s[0] != '0');
        for(int i=2;i<=s.size();i++)
        {
            // Take one digit
            if(s[i - 1] != '0')
            {
                dp[i] += dp[i - 1];
            }

            // Take two digits
            int num = (s[i - 2] - '0') * 10
                    + (s[i - 1] - '0');

            if(num >= 10 && num <= 26)
            {
                dp[i] += dp[i - 2];
            }   
        }
       
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,0);
        f(s,dp);
        return dp[s.size()];
        
    }
};
