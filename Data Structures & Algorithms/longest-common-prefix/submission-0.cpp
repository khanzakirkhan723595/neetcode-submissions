class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str=strs[0];
        int l=INT_MAX;
        for(int i=1;i<strs.size();i++)
        {
            int n=0;
            for(int j=0;j<str.size();j++ )
            {
                if(str[j]==strs[i][j])
                {
                    n++;

                }
                else
                    break;
            }
            l=min(l,n);

            
        }
        return str.substr(0,l);
        
    }
};