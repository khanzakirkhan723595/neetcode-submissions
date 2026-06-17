class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<pair<int,int>> st;
        vector<int> res(n,0);
        for(int i=0;i<n;i++)
        {
            int t=temperatures[i];
            while(!st.empty() && t>st.top().first )
            {
                int idx=st.top().second;
                st.pop();
                res[idx]=i-idx;
                


            }
            st.push({t,i});
        }
        return res;
        
    }
};
