class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int mul=1;
        vector<int> preres(n);
        vector<int> res(n);
        preres[0]=1;
        for(int i=1;i<n;i++)
        {
            mul=mul*nums[i-1];
            preres[i]=mul;
        }
        int mul2=1;
        res[n-1]=preres[n-1];
        for(int i=n-2;i>=0;i--)
        {
            mul2=mul2*nums[i+1];

            res[i]=preres[i]*mul2;
        }
        return res;




    }
};
