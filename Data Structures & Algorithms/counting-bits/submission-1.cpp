class Solution {
public:
    
    // int f(int n)
    // {
    //     int ans=0;
    //     while(n > 0)
    //     {
    //         int r = n % 2;
    //         if(r==1)
    //             ans++;
    //         n = n / 2;
    //     }
    //     return ans;
    // }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        // for(int i=0;i<=n;i++)
        // {
        //     ans.push_back(f(i));
        // }
        for(int i=0;i<=n;i++)
        {
            int cnt=0;
            int n1=i;
            while(n1>0)
            {
                if(n1 & 1)
                {
                    cnt++;
                }
                n1=n1>>1;
                    
            }
            ans[i]=cnt;
        }
        

        


        return ans;
        
    }
};
