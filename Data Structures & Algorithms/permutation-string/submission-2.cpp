class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<int> freqs1(26,0);
        vector<int> freqs2(26,0);
        if(n1>n2)
        {
            return false;
        }
        for(char c:s1)
        {
            freqs1[c-'a']++;
            
        }
        for(int i=0;i<n1;i++)
        {
            freqs2[s2[i]-'a']++;
        }
        if(freqs1==freqs2)
        {
            return true;
        }
        int l=0;
        for(int r=n1;r<n2;r++)
        {
            freqs2[s2[r]-'a']++;
            freqs2[s2[l]-'a']--;
            l++;
            if(freqs1==freqs2)
            {
                return true;
            }
        }
        return false;
        
    }
};
