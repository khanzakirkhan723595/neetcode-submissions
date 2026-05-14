class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second,it->first});
        }
        vector<int> res;
        for(int i=0;i<k;i++)
        {
            pair<int,int> pr;
            pr=pq.top();
            pq.pop();
            res.push_back(pr.second);
        }
        return res;

        
    }
        
};
