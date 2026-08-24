class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(int i=0;i<strs.size();i++)
        {
            int sz=strs[i].size();
            res.append(to_string(sz));
            res.push_back('#');
            res.append(strs[i]);
        }
        return res;

    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.size())
        {
            int j=i;
            while(s[j]!='#')
                j++;
            int ss=stoi(s.substr(i,j-i));
            i=j+1;
            j=i+ss;
            res.push_back(s.substr(i,ss));
            i=j;
        }
        return res;

    }
};
