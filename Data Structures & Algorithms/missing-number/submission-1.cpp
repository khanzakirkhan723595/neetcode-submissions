class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xnum=0;
        int n=nums.size();
        //int tsum=n*(n+1)/2;
        for(int i=0;i<=n;i++)
        {
            xnum^=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            xnum^=nums[i];
        }
        return xnum;
        
    }
};
