class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});

        }
        
        while(!pq.empty())
        {
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            for(auto &ngb : adj[u])
            {
                int v=ngb.first;
                int w=ngb.second;
                if(dist[v]>d+w)
                {
                    dist[v]=d+w;
                    pq.push({dist[v],v});

                }
            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<dist.size();i++)
        {
            if(i==0)
                continue;
            if(i>0 && dist[i]==INT_MAX)
                return -1;
            maxi=max(maxi,dist[i]);
        }
        return maxi;
        
    }
};
