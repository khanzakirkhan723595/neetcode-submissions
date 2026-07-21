class Solution {
public:
    bool dfs(int src,int par ,vector<vector<int>> &adj,int n,vector<int> &vis)
    {
        if(vis[src]==1)
            return false;
        vis[src]=1;
        for(int ngb:adj[src])
        {
            if(!vis[ngb])
            {
                if(dfs(ngb,src,adj,n,vis))
                    return true;
            }
            else if(ngb!=par)
                return true;
            
        }
        return false;
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> ta(n+1);
        //vector<int> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> vis(n+1,0);
            int u=edges[i][0];
            int v=edges[i][1];
            ta[u].push_back(v);
            ta[v].push_back(u);
            //cout<<u<<","<<v<<endl;
            if(dfs(u,-1,ta,n,vis))
            {
                return {u,v};

            }
        }
        return {};
        
    }
};
