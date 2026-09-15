class Solution {
public:

    bool isPal(string &str)
    {
        int l = 0;
        int r = str.size() - 1;

        while(l <= r)
        {
            if(str[l] == str[r])
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    void f(int i, string &s, vector<string> &curr,
           vector<vector<string>> &ans)
    {
        // We have used the entire string
        if(i == s.size())
        {
            ans.push_back(curr);
            return;
        }

        // Try every possible ending position
        for(int j = i; j < s.size(); j++)
        {
            string str = s.substr(i, j-i+1);

            // We can only take this piece if it is palindrome
            if(isPal(str))
            {
                curr.push_back(str);

                f(j+1, s, curr, ans);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> curr;

        f(0, s, curr, ans);

        return ans;
    }
};