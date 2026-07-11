class Solution {
public:
    //unordered_map<vector<int>,bool> mp;
    vector<vector<int>> res;
    void f(int idx,vector<int> vec,vector<int>& nums)
    {
        res.push_back(vec);
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i]==nums[i-1])
                continue;
            vec.push_back(nums[i]);
            f(i+1,vec,nums);
            vec.pop_back();
            //f(idx+1,vec,nums);

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> vec;
        f(0,vec,nums);
        return res;
        
    }
};
