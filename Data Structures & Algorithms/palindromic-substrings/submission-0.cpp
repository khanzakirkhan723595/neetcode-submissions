class Solution {
public:
    
    int countSubstrings(string s) {
        int ans = 0;

for (int i = 0; i < s.size(); i++)
{
    // Check odd-length palindromes
    int l = i;
    int r = i;

    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
        ans++;
        l--;
        r++;
    }

    // Check even-length palindromes
    l = i;
    r = i + 1;

    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
        ans++;
        l--;
        r++;
    }
}

return ans;
        
    }
};
