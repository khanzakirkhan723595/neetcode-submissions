class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<pair<int, int>> st;
        int best = 0;

        for (int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : h[i];
            int start = i;

            while (!st.empty() && curr <= st.top().first) {
                int height = st.top().first;
                int idx = st.top().second;
                st.pop();

                best = max(best, height * (i - idx));
                start = idx;
            }

            st.push({curr, start});
        }

        return best;
    }
};