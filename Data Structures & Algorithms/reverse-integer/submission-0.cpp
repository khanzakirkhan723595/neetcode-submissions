class Solution {
public:
    int reverse(int x) {
        long long res=0;
        int sign=1;
        if(x<0)
        {
            sign=-1;
            x=-x;
        }
        while(x>0)
        {
            int r=x%10;
            x=x/10;
            res=res*10+r;
        }
        if(res<=INT_MIN || res>=INT_MAX)
        {
            return 0;
        }
        return res*sign;
        
    }
};
