class Solution {
public:
    int f(int idx,vector<int>& nums)
    {
        
        if(idx>=nums.size())
        {
            return 1;

        }
        int pick=f(idx+1,nums)*(nums[idx]);
        int npick=f(idx+1,nums)*1;
        
        return max(pick,npick);
    }
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        int pmax=nums[0];
        int maxi=nums[0];
        int pmin=nums[0];
        for(int i=1;i<n;i++)
        {
            int cmax=max(nums[i],max(pmax*nums[i],pmin*nums[i]));
            int cmin=min(nums[i],min(pmax*nums[i],pmin*nums[i]));
            pmax=cmax;
            maxi=max(maxi,cmax);
            pmin=cmin;

        }
        
        return maxi;

        
    }
};
