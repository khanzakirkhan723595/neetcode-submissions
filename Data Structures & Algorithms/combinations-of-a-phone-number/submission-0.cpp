
class Solution {
public:
    void f(int i, unordered_map<int,string>& m, string digits,
           string str, vector<string>& res)
    {
        if(str.size() == digits.size())
        {
            res.push_back(str);
            return;
        }

        int n = digits[i] - '0';
        string temp = m[n];

        for(int j = 0; j < temp.size(); j++)
        {
            str.push_back(temp[j]);
            f(i+1, m, digits, str, res);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> m;
        vector<string> res;

        if(digits.empty())
            return res;

        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";

        string str = "";
        f(0, m, digits, str, res);

        return res;
    }
};
