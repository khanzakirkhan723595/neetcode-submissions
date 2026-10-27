class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> st;
        vector<int> res(n,0);
        for(int i=0;i<n;i++)
        {
            int t=temperatures[i];
            while(!st.empty() && t>temperatures[st.top()] )
            {
                int idx=st.top();
                st.pop();
                res[idx]=i-idx;
                


            }
            st.push(i);
        }
        return res;
        
    }
};
