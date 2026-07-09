class Solution {
public:
    vector<vector<int>> res;
    void allpossible(vector<int>ans,int idx,vector<int>& nums,int sum,int target)
    {
        
        if(sum == target)
    {
        res.push_back(ans);
        return;
    }

    if(idx >= nums.size() || sum > target)
        return;

    // Take current number (stay at same index)
    ans.push_back(nums[idx]);
    allpossible(ans, idx, nums, sum + nums[idx], target);

    // Don't take current number (move to next)
    ans.pop_back();
    allpossible(ans, idx + 1, nums, sum, target);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> ans;
        allpossible(ans,0,nums,0,target);
        return res;
        
    }
};
