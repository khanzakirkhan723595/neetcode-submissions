class Solution {
public:
    bool check(string s,int l,int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0;
        int n=s.size();
        int r=s.size()-1;
        int cnt=0;
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else{
                
                return check(s,l+1,r) || check(s,l,r-1);
                
            }
        }
        return true;
        
    }
};