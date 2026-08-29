class Solution {
public:
    
    int f(int n)
    {
        int ans=0;
        while(n > 0)
        {
            int r = n % 2;
            if(r==1)
                ans++;
            n = n / 2;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            ans.push_back(f(i));
        }

        


        return ans;
        
    }
};
