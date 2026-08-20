class Solution {
public:

    string bita(long long a)
    {
        string s = "";

        if(a == 0)
            return "0";

        while(a > 0)
        {
            int r = a % 2;
            s.push_back(r + '0');
            a /= 2;
        }

        return s;
    }

    string addBinary(string a, string b)
    {
        string res = "";

        int i = 0;
        int j = 0;
        int carry = 0;

        while(i < a.size() || j < b.size())
        {
            int x = 0;
            int y = 0;

            if(i < a.size())
                x = a[i++] - '0';

            if(j < b.size())
                y = b[j++] - '0';

            int sum = x + y + carry;

            res.push_back((sum % 2) + '0');

            carry = sum / 2;
        }

        if(carry)
            res.push_back('1');

        return res;
    }

    string subtractBinary(string a, string b)
    {
        string res = "";
        int borrow = 0;

        for(int i = 0; i < a.size(); i++)
        {
            int x = a[i] - '0';

            int y = 0;
            if(i < b.size())
                y = b[i] - '0';

            int value = x - borrow - y;

            if(value < 0)
            {
                value += 2;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }

            res.push_back(value + '0');
        }

        while(res.size() > 1 && res.back() == '0')
            res.pop_back();

        return res;
    }

    long long binaryToDecimal(string s)
    {
        long long ans = 0;
        long long power = 1;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1')
                ans += power;

            power *= 2;
        }

        return ans;
    }

    int getSum(int a, int b)
    {
        bool negA = a < 0;
        bool negB = b < 0;

        long long aa = a;
        long long bb = b;

        if(aa < 0)
            aa = -aa;

        if(bb < 0)
            bb = -bb;

        string sa = bita(aa);
        string sb = bita(bb);

        // +a + +b
        if(!negA && !negB)
        {
            return binaryToDecimal(addBinary(sa, sb));
        }

        // -a + -b
        if(negA && negB)
        {
            return -binaryToDecimal(addBinary(sa, sb));
        }

        // -a + b
        if(negA && !negB)
        {
            if(bb >= aa)
                return binaryToDecimal(subtractBinary(sb, sa));
            else
                return -binaryToDecimal(subtractBinary(sa, sb));
        }

        // a + -b
        if(!negA && negB)
        {
            if(aa >= bb)
                return binaryToDecimal(subtractBinary(sa, sb));
            else
                return -binaryToDecimal(subtractBinary(sb, sa));
        }

        return 0;
    }
};