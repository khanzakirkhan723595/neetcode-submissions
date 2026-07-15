class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==-1)
                {
                    continue;
                }
                if(grid[i][j]==0)
                {
                    q.push({{i,j},0});
                }
            }
        }
        int mini=INT_MAX;
        while(q.size()>0)
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int ans=q.front().second;
            int mini=INT_MAX;
            mini=min(mini,ans);
            grid[i][j]=mini;
            q.pop();
            if(i-1>=0 && visited[i-1][j]==0 && grid[i-1][j]==2147483647)
            {
                q.push({{i-1,j},ans+1});
                visited[i-1][j]=1;
            }
            if(j+1<n && visited[i][j+1]==0 && grid[i][j+1]==2147483647)
            {
                q.push({{i,j+1},ans+1});
                visited[i][j+1]=1;
            }
            if(i+1<m && visited[i+1][j]==0 && grid[i+1][j]==2147483647)
            {
                q.push({{i+1,j},ans+1});
                visited[i+1][j]=1;
            }
            if(j-1>=0 && visited[i][j-1]==0 && grid[i][j-1]==2147483647)
            {
                q.push({{i,j-1},ans+1});
                visited[i][j-1]=1;
            }

        }

        
    }
};
 