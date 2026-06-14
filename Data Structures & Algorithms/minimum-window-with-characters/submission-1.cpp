class Solution {
public:
    string minWindow(string s, string t)
{
    int ns = s.size();
    int nt = t.size();

    if(ns < nt)
        return "";

    unordered_map<char,int> mp;

    for(char c : t)
        mp[c]++;

    int cnt = 0;
    int l = 0;

    int mini = INT_MAX;
    int start = -1;

    for(int r = 0; r < ns; r++)
    {
        if(mp[s[r]] > 0)
            cnt++;

        mp[s[r]]--;

        while(cnt == nt)
        {
            if(r - l + 1 < mini)
            {
                mini = r - l + 1;
                start = l;
            }

            mp[s[l]]++;

            if(mp[s[l]] > 0)
                cnt--;

            l++;
        }
    }

    if(start == -1)
        return "";

    return s.substr(start, mini);
}
};
