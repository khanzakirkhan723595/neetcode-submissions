class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        string str1 = "";
        while(n > 0)
        {
            int r = n % 2;
            str1.push_back(r + '0');
            n = n / 2;
        }

        
        while(str1.size() < 32)
        {
            str1.push_back('0');
        }

        
        uint32_t ans = 0;
        uint32_t power = 1;

        
        for(int i = 31; i >= 0; i--)
        {
            if(str1[i] == '1')
            {
                ans += power;
            }

            power *= 2;
        }

        return ans;
    }
};