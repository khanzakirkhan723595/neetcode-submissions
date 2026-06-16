class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        int l=0;
        int r=0;
        vector<int> res(n,0);
        bool is=false;
        while(r<n)
        {
            while(r<n && temperatures[r]<=temperatures[l])
            {
                r++;
                if(r==n)
                {

                    break;

                }
            }
            if(r==n)
            {
                l++;
                r=l;
                continue;
            }
            res[l]=r-l;
            l++;
            r=l;
        }
        return res;
        
    }
};
