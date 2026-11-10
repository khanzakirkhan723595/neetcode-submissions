class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> st;
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(i!=j)
                {
                    if (words[i].find(words[j]) != std::string::npos)
                    {
                        st.insert(words[j]);
                    }
                }
            }
        }
        for(auto it:st)
            ans.push_back(it);
        return ans;
        
    }
};