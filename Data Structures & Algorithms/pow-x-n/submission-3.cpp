class Solution {
public:
    double pow(double x,int n)
    {
        if(x==0)
            return 0;
        if(n==0)
            return 1;
        
        if(n%2)
            return x*pow(x*x,n/2);
        else{
            return pow(x*x,n/2);
        }

    }
    double myPow(double x, int n) {
        int n1=n;
        if(n<0)
            n1=-n;
        double res=pow(x,n1);
        if(n<0)
            return 1/res;
        else
            return res;
        
    }
};
