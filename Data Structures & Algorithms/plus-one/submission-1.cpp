class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num=0;
        for(int i=0;i<digits.size();i++)
        {
            num=num*10+digits[i];
        }
        num=num+1;
        digits.clear();
        while(num>0)
        {
            int r=num%10;
            digits.push_back(r);
            num=num/10;
        }
        reverse(digits.begin(),digits.end());
        return digits;
        
    }
};
