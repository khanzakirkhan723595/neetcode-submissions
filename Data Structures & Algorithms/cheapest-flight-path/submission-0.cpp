
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v, wt});
        }

        for(int i = 0; i <= k; i++) {
            vector<int> temp = prices;

            for(int u = 0; u < n; u++) {
                if(prices[u] == INT_MAX)
                    continue;

                for(int j = 0; j < adj[u].size(); j++) {
                    int v = adj[u][j].first;
                    int wt = adj[u][j].second;

                    if(temp[v] > prices[u] + wt) {
                        temp[v] = prices[u] + wt;
                    }
                }
            }

            prices = temp;
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
