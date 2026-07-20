class Solution {
public:
    bool dfs(int src,int par,vector<vector<int>> &adj,int n,vector<int> &vis)
    {
        if(vis[src]==1)
            return false;
        vis[src]=1;
        for(int ngb:adj[src])
        {
            if(!vis[ngb])
            {
                dfs(ngb,src,adj,n,vis);
            }
            else if(ngb!=par)
            {
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
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
        bool iscycle=false;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                if(dfs(i,-1,adj,n,vis))
                {
                    iscycle=true;;
                }
                
                
            }
            
        }
        
        if(!iscycle && cnt==1)
            return true;
        else
            return false;

    }
};
