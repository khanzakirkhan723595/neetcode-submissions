class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=1;
        int idx=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                cnt++;
                if(cnt>n/2)
                {
                    return nums[i];
                }
            }
            else{
                cnt=1;
            }
            
            
        }
        return nums[0];
    }
};