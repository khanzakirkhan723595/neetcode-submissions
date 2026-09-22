class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> st;
        for(int i=0;i<operations.size();i++)
        {
            string s=operations[i];
            if(s=="+")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                int z=x+y;
                st.push(y);
                st.push(x);
                st.push(z);
            }
            else if(s=="D")
            {
                int x=st.top();
                st.push(2*x);
            }
            else if(s=="C")
                st.pop();
            else{
                st.push(stoi(s));
            }
        }
        int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
        
    }
};