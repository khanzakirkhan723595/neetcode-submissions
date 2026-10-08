class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> temp;
        temp.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<temp.back()[1])
            {
                cnt++;
                if(intervals[i][1] < temp.back()[1])
                    temp.back() = intervals[i];
                
            }
            else{
                temp.push_back(intervals[i]);
            }

        }
        return cnt;
        
    }
};
