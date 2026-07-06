class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,int>,
                    vector<pair<float,int>>,
                    greater<pair<float,int>>
                    >pq;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            float d=sqrt((x*x)+(y*y));
            pq.push({d,i});
        }
        vector<vector<int>> res;
        for(int i=0;i<k;i++)
        {
            pair<int,int> p=pq.top();
            pq.pop();
            int idx=p.second;
            res.push_back(points[idx]);

        }
        return res;
        
    }
};
