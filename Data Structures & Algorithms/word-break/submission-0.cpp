class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        vector<bool> dp(s.size() + 1, false);

        dp[0] = true;
        for(int i=0;i<wordDict.size();i++)
        {
            st.insert(wordDict[i]);
        }

        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                // Check dp[j]

                // Extract:
                // s.substr(j, i-j)
                string word=s.substr(j,i-j);

                // Check whether it is in the dictionary

                // If both are true:
                // dp[i] = true
                if(dp[j]==true && st.count(word))
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];


        
    }
};
