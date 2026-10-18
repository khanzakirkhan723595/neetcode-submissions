class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pl=p.size();
        int sl=s.size();
        vector<int> res;
        if(sl<pl)
            return res;
        vector<int> count_s(26,0),count_p(26,0);
        for(int i=0;i<pl;i++)
        {
            count_p[p[i]-'a']++;
            count_s[s[i]-'a']++;
        }
        if(count_s==count_p)
        {
            res.push_back(0);
        }
        for(int i= pl;i<sl;i++)
        {
            count_s[s[i-pl]-'a']--;
            count_s[s[i]-'a']++;
            if(count_s==count_p)
            {
                res.push_back(i-pl+1);
            }
        }
        return res;

    }
};
