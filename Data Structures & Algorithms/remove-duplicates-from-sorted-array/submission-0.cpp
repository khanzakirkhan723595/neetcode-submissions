class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]=INT_MAX;
                cnt++;
            }

        }
        sort(nums.begin(),nums.end());
        return n-cnt;
        
    }
};