class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> vec;
        for(int i=0;i<names.size();i++)
        {
            vec.push_back({heights[i],names[i]});
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        vector<string> ans;
        for(int i=0;i<vec.size();i++)
        {
            ans.push_back(vec[i].second);
        }
        return ans;
        
    }
};