class Solution {
public:
    vector<string> result;
    void dfs(string airport,unordered_map<string,priority_queue<string,vector<string>,greater<string>>> &adj)
    {
        while(!adj[airport].empty())
        {
            string nxtarpt=adj[airport].top();
            adj[airport].pop();

            dfs(nxtarpt,adj);
        }
        result.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
        for(auto & t:tickets)
        {
            string s1=t[0];
            string s2=t[1];
            adj[s1].push(s2);
        }
        dfs("JFK",adj);
        reverse(result.begin(),result.end());
        return result;

    
        
    }
};
