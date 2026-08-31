class CountSquares {
public:
    map<pair<int,int>,int> mp;
    int n;
    CountSquares() {
        n=0;

        
        
    }
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
        
    }
    
    
    int count(vector<int> point) {
        int qx=point[0];
        int qy=point[1];
        int ans=0;
        for(auto & it: mp)
        {
            int x=it.first.first;
            int y=it.first.second;
            if(x == qx || y == qy)
                continue;
            if(abs(qx - x) != abs(qy - y))
                continue;
            pair<int,int> point1={x,qy};
            pair<int,int> point2={qx,y};
            if(mp.count(point1) && mp.count(point2))
            {
                ans+=mp[point1]*mp[point2]*mp[{x,y}];
            }
        }
        return ans;

        
    }
};
