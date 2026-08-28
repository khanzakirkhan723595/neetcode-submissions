/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(),
            [](Interval &a, Interval &b) {
                return a.start < b.start;
            });
        int s=intervals[0].start;
        int e=intervals[0].end;
        for(int i=1;i<n;i++)
        {
            int si=intervals[i].start;
            int ei=intervals[i].end;
            if(si<e)
            {
                return false;

            }
            s=si;
            e=ei; 
        }
        return true;
        
    }
};
