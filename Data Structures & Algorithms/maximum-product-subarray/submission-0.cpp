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
        vector<int> maxi(n);
        maxi[0]=nums[0];
        vector<int> mini(n);
        mini[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            maxi[i]=max(nums[i],max(maxi[i-1]*nums[i],mini[i-1]*nums[i]));
            mini[i]=min(nums[i],min(maxi[i-1]*nums[i],mini[i-1]*nums[i]));

        }
        sort(maxi.begin(),maxi.end());
        return maxi[maxi.size()-1];

        
    }
};
