class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
    vector<int> ans;

    if(k == 1)
        return nums;

    int l = 0;

    while(l + k <= n)
    {
        int maxi = INT_MIN;

        for(int r = l; r < l + k; r++)
        {
            maxi = max(maxi, nums[r]);
        }

        ans.push_back(maxi);
        l++;
    }

    return ans;
    }
};
