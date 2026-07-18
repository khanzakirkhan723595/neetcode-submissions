class Solution {
public:
    bool dfs(int src,vector<vector<int>> & adj,int n,vector<int> &vis,vector<int> & recpath)
    {
        if(src<0 || src>=n || vis[src]==1)
            return false;
        vis[src]=1;
        recpath[src]=1;
        for(int ngb : adj[src])
        {
            if(!vis[ngb])
            {
                if(dfs(ngb,adj,n,vis,recpath))
                {
                    return true;
                }
            }
            else if(recpath[ngb]==1){
                return true;

            }
        }
        recpath[src]=-1;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses,0);
        vector<int> recpath(numCourses,-1);
        for(int i=0;i<prerequisites.size();i++)
        {
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,numCourses,vis,recpath))
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};
