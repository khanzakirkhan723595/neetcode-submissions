class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        if(n==1 && nums[0]==0)
            return 0;
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1] )
            {
                if(nums[i]==1)
                    cnt++;
                else
                    continue;
            }
            else{
                cnt++;
                maxi=max(maxi,cnt);
                cnt=0;
            }

        }
        if(nums[n-1]==1)
        {
            cnt++;
            maxi=max(maxi,cnt);
        }
        return maxi==INT_MIN?0:maxi;
        
    }
};