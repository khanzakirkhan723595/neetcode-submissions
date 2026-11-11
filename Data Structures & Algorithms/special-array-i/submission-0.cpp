class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return true;
        }
        for(int i=1;i<n;i++)
        {
            int x=nums[i-1];
            int y=nums[i];
            if((x%2==1 && y%2==0) || (x%2==0 && y%2==1) )
                continue;
            else
                return false;
            
        }
        return true;
        
    }
};