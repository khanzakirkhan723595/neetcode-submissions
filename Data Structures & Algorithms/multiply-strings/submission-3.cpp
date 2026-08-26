class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        if(num1[0]=='0' || num2[0]=='0')
        {
            return "0";
        }
        vector<int> result(n1+n2,0);
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                int pos=i+j+1;
                int product=(num1[i]-'0')*(num2[j]-'0');
                result[pos]+=product;
                result[pos-1]+=result[pos]/10;
                result[pos]=result[pos]%10;
            }
            
        }
        string res;
        int i = 0;

        // Skip leading zeros
        while(i < result.size() && result[i] == 0)
            i++;

        while(i < result.size())
        {
            res.push_back(result[i] + '0');
            i++;
        }
        return res;
        
    }
};
