class Solution {
public:
    bool dfs(int src,vector<vector<int>> & adj,int n,vector<int> &vis,vector<int> & res,vector<int> & recpath)
    {
        if(src<0 || src>=n || vis[src]==1)
            return false ;
        vis[src]=1;
        recpath[src]=1;
        for(int ngb : adj[src])
        {
            if(!vis[ngb])
            {
                if(dfs(ngb,adj,n,vis,res,recpath))
                    return true;
            }
            else if(recpath[ngb]==1)
            {
                
                return true;
            }
            
        }
        res.push_back(src);
        recpath[src]=0;
        return false;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses,0);
        vector<int> recpath(numCourses,0);
        vector<int> res;
        for(int i=0;i<prerequisites.size();i++)
        {
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];
            adj[u].push_back(v);
        }
        bool  isCycle=false;
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,numCourses,vis,res,recpath))
                {
                    return {};
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
        
        
    
        
    }
};
