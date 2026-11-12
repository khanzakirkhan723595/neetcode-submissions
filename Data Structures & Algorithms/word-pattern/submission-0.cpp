class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> str;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                str.push_back(s.substr(j, i - j));
                j = i + 1;
            }
            if (i == s.size() - 1) {
                str.push_back(s.substr(j, i - j + 1));
            }
        }
        
        if (pattern.size() != str.size()) {
            return false;
        }
        
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        for (int i = 0; i < pattern.size(); i++) {
            if (mp.count(pattern[i]) && mp[pattern[i]] != str[i]) {
                return false;
            }
            if (mp2.count(str[i]) && mp2[str[i]] != pattern[i]) {
                return false;
            }
            mp[pattern[i]] = str[i];
            mp2[str[i]] = pattern[i];
        }
        return true;
    }
};