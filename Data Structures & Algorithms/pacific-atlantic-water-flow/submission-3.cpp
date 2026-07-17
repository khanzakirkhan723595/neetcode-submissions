class Solution {
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> pv(m,vector<int>(n,0));
        vector<vector<int>> av(m,vector<int>(n,0));
        for(int j=0;j<n;j++)
        {
            dfs(0,j,heights[0][j],heights,m,n,pv);
        }
        for(int i=0;i<m;i++)
        {
            dfs(i,0,heights[i][0],heights,m,n,pv);
        }
        for(int j=0;j<n;j++)
        {
            dfs(m-1,j,heights[m-1][j],heights,m,n,av);
        }
        for(int i=0;i<m;i++)
        {
            dfs(i,n-1,heights[i][n-1],heights,m,n,av);
        }

        vector<vector<int>> res;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pv[i][j]==1 && av[i][j]==1)
                {
                    res.push_back({i,j});
                }
            }
        }
        return res;
        
    }

private:
    void dfs(int i,int j,int ele,
         vector<vector<int>>& heights,
         int m,int n,
         vector<vector<int>>& visited)
        {
            if(i<0 || i>=m || j<0 || j>=n || visited[i][j])
                return;

            if(heights[i][j] < ele)
                return;

            visited[i][j]=1;

            dfs(i-1,j,heights[i][j],heights,m,n,visited);
            dfs(i+1,j,heights[i][j],heights,m,n,visited);
            dfs(i,j-1,heights[i][j],heights,m,n,visited);
            dfs(i,j+1,heights[i][j],heights,m,n,visited);
        }
};