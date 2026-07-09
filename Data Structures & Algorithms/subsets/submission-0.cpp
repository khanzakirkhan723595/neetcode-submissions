class Solution {
public:
    vector<vector<int>> res;
    void allpossible(vector<int>ans,int idx,vector<int>& nums)
    {
        
        if(idx>=nums.size())
        {
            res.push_back(ans);
            return;
            //ans={0};

        }
        ans.push_back(nums[idx]);
        allpossible(ans,idx+1,nums);
        ans.pop_back();
        allpossible(ans,idx+1,nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        allpossible(ans,0,nums);
        return res;
        
    }
};
