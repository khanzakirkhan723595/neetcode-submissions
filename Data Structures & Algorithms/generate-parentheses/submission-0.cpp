class Solution {
public:
    vector<string> res;
    void f(string str,int n,int open, int close)
    {
        if(open==n && close==n)
        {
            res.push_back(str);
            str="";
            return;
        }
        if(open<n)
        {
            
            f(str+"(",n,open+1,close);
        }
        if(close<open)
        {
            
            f(str+")",n,open,close+1);
        }


    }
    vector<string> generateParenthesis(int n) {
        string str="";
        f(str,n,0,0);
        return res;
        
    }
};
