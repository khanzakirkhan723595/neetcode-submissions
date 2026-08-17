class Solution {
public:
    bool checkValidString(string s) {

    int n = s.size();
    int low=0;
    int high=0;
    for(int i=0;i<n;i++)
    {
        char c=s[i];
        if(c=='(')
        {
            low++;
            high++;
        }
        if(c==')')
        {
            low--;
            high--;
        }
        if(c=='*')
        {
            low--;
            high++;
        }
        low=max(0,low);
        if(high<0)
            return false;

    }
    return low==0;

    
}
};
