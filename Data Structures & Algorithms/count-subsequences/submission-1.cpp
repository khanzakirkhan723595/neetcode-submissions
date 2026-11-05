class Solution {
public:
    int f(int i,int j,string &str,string &s,string &t,vector<vector<int>> &dp)
    {
        if(i==s.size()||j == t.size())
        {
            if(str==t)
                return 1;
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        // if(idx==s.size())
        // {
        //     if(str==t)
        //         return 1;
        //     return 0;
        // }
        // //pick
        // str.push_back(s[idx]);
        // int p=f(idx+1,str,s,t);
        // str.pop_back();
        // int np=f(idx+1,str,s,t);
        // return 1+max(p,np);
        int ic=0;
        if(i<s.size() && j<t.size() && s[i]==t[j])
        {
            str.push_back(s[i]);
            ic=f(i+1,j+1,str,s,t,dp);
            str.pop_back();
        }
        int nic=f(i+1,j,str,s,t,dp);    
        return dp[i][j]=ic+nic;

    }
    int numDistinct(string s, string t) {
        string str;
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return f(0,0,str,s,t,dp);
        
    }
};
