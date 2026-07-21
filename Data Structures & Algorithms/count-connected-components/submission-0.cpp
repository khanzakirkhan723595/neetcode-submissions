class Solution {
public:
    void dfs(int src,int par,vector<vector<int>> &adj,int n,vector<int> &vis)
    {
        if(vis[src]==1)
            return;
        vis[src]=1;
        for(int ngb:adj[src])
        {
            if(!vis[ngb])
            {
                dfs(ngb,src,adj,n,vis);
            }
            
        }
        
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,-1,adj,n,vis);
                
                
            }
            
        }
        return cnt;
        
        
            
        

    

    }
};
