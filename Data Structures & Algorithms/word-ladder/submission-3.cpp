class Solution {
public:
    bool ngb(string &s1,string &s2)
    {
        int cnt=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
                cnt++;


        }
        if(cnt==1)
            return true;
        else
            return false;

    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        if(words.count(endWord) == 0)
            return 0;
        vector<string> twl;
        twl.push_back(beginWord);

        for(auto &w : wordList)
            twl.push_back(w);
        
        queue<string> q;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<twl.size();i++)
        {
            for(int j=0;j<twl.size();j++)
            {
                bool isngb = ngb(twl[i],twl[j]);
                if(isngb)
                {
                    mp[twl[i]].push_back(twl[j]);
                }
            }
        }
        
        q.push(beginWord);
        int level=1;
        unordered_set<string> st;
        st.insert(beginWord);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                string s=q.front();
                q.pop();
                if(s==endWord)
                    return level;
                auto &ngbv = mp[s];
                for(int i=0;i<ngbv.size();i++)
                {
                    if(st.count(ngbv[i])==0)
                    {
                        st.insert(ngbv[i]);
                        q.push(ngbv[i]);
                    }

                }

            }
            level++;
        }
        return 0;

        
    }
    
};
