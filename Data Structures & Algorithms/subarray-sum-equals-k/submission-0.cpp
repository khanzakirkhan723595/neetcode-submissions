class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        mp[0]=1;
        int pref=0;
        int ans=0;
        for(int x:nums)
        {
            pref+=x;
            ans+=mp[pref-k];
            mp[pref]++;

        }
        return ans;
        
    }
};