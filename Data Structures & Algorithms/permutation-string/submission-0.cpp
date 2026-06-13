class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        int l=0;
        int r=0;
        int n2=s2.size();
        int n1=s1.size();
        while(r<n2)
        {
            while(r-l+1<n1)
            {
                r++;
            }
            if(r-l+1==n1)
            {
                string sub=s2.substr(l,r-l+1);
                sort(sub.begin(),sub.end());
                if(sub==s1)
                {
                    return true;
                }
                else{
                    l++;
                }
            }
        }
        return false;
        
    }
};
