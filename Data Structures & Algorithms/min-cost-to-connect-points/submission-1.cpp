class DisjointSet{
    vector<int> parent,size;
    public:
        DisjointSet(int n)
        {
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }
        }
        int findUPar(int node){
            if(node==parent[node])
                return node;
            return parent[node]=findUPar(parent[node]);
        }
        void unionBySize(int u,int v)
        {
            int pu=findUPar(u);
            int pv=findUPar(v);
            if(pu==pv)
                return;
            if(size[pu]<size[pv])
            {
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
            else{
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
        }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>> edges;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int d=abs(x1-x2)+abs(y1-y2);
                edges.push_back({d,{i,j}});
            }
        }
        sort(edges.begin(),edges.end());
        DisjointSet ds(n);
        int mst=0;
        for(auto &it:edges)
        {
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            //if u and v are in different components
            if(ds.findUPar(u)!=ds.findUPar(v))
            {
                mst+=wt;
                ds.unionBySize(u,v);
            }

        }
        return mst;

        

        
    }
};
