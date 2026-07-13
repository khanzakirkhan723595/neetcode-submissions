class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited,int &ans)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()|| visited[i][j]==1 ||grid[i][j]==0)
            return;
        visited[i][j]=1;
        ans++;
        dfs(i-1,j,grid,visited,ans);
        dfs(i,j-1,grid,visited,ans);
        dfs(i+1,j,grid,visited,ans);
        dfs(i,j+1,grid,visited,ans);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int maxi=INT_MIN;
        int ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    ans=0;
                    dfs(i,j,grid,visited,ans);
                    maxi=max(maxi,ans);
                    

                }
            }
        }
        return maxi==INT_MIN?0:maxi;
        
    }
};
