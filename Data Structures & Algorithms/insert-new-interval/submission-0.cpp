class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // Step 1: Add new interval
        intervals.push_back(newInterval);

        // Step 2: Sort intervals
        sort(intervals.begin(), intervals.end());

        // Step 3: Merge overlapping intervals
        vector<vector<int>> temp;

        temp.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++)
        {
            int f = intervals[i][0];
            int s = intervals[i][1];

            // Overlap
            if(f <= temp.back()[1])
            {
                temp.back()[1] = max(temp.back()[1], s);
            }
            else
            {
                temp.push_back(intervals[i]);
            }
        }

        return temp;
    }
};