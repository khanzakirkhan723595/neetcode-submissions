class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=1;
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int ans=nums[0];
        int minil=INT_MAX;
        while(r<n && l<n)
        {
            
            
            if(ans>=target)
            {
                
            
                    minil=min(minil,r-l);
                    ans-=nums[l];
                    l++;
                


            }
            else if(ans<target)
            {
                ans+=nums[r];
                r++;
                if(r==n)
                {
                    while(ans>=target)
                    {
                        minil=min(minil,r-l);
                        ans-=nums[l];
                        l++;

                    }
                }
            }

        }
        return minil==INT_MAX?0:minil;
        
    }
};