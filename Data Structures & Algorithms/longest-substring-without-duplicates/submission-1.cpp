class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int msize=0;
        int l=0;
        int r=0;
        unordered_map<char,int> mp;
        while(r<n)
        {
            if(mp.count(s[r]))
            {
                //mp.erase(s[l]);
                l=max(mp[s[r]]+1,l);
            }
            mp[s[r]]=r;
            int size=r-l+1;
            msize=max(msize,size);
            r++;

        }
        return msize;
        
    }
};
