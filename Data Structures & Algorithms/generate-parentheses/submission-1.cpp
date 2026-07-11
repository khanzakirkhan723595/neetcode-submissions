class Solution {
public:
    vector<string> res;
    void f(string str,int n,int open, int close)
    {
        if(open==n && close==n)
        {
            res.push_back(str);
            //str="";
            return;
        }
        if(open<n)
        {
            str.push_back('(');
            f(str,n,open+1,close);
            str.pop_back();
        }
        if(close<open)
        {
            str.push_back(')');
            f(str,n,open,close+1);
            str.pop_back();
        }


    }
    vector<string> generateParenthesis(int n) {
        string str="";
        f(str,n,0,0);
        return res;
        
    }
};
