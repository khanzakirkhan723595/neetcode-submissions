class Solution {
public:
    int sd(int n)
    {   int sum=0;
        while(n>=1)
        {
            int r=n%10;
            sum+=r*r;
            n=n/10;
        }
        return sum;
    }
    unordered_set<int> st;
    bool isHappy(int n) {
        int n1=n;
        while(n1!=1)
        {
            
            if(n1==1)
                return true;
            if(st.count(n1))
            {
                return false;
            }
            else{
                st.insert(n1);
            }
            n1=sd(n1);

        }
        return true;
        
        
    }
};
