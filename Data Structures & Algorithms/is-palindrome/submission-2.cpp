class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            str.push_back(s[i]);
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            str.push_back(s[i] + 32);
        }
        else if(s[i] >= '0' && s[i] <= '9')
        {
            str.push_back(s[i]);
        }
    }

    int n = str.size();

    for(int i = 0; i < n/2; i++)
    {
        if(str[i] != str[n-i-1])
        {
            return false;
        }
    }

    return true;
        
    }
};
