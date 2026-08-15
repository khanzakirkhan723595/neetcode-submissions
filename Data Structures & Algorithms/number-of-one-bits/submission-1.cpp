class Solution {
public:
    int hammingWeight(uint32_t n) {
        // string str="";
        // while(n>0)
        // {
        //     int r=n%2;
        //     char d=r+'0';
        //     str.push_back(d);
        //     n=n/2;
        // }
        // int cnt=0;
        // for(int i=0;i<str.size();i++)
        // {
        //     if(str[i]=='1')
        //         cnt++;
        // }
        // return cnt;

        //method 2
        int cnt = 0;

        while(n > 0)
        {
            if(n % 2 == 1)
                cnt++;

            n = n / 2;
        }

        return cnt;
    }
};
