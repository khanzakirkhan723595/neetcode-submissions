class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

    vector<pair<int,double>> arr;

    for(int i=0;i<n;i++)
    {
        double t = (double)(target-position[i]) / speed[i];
        arr.push_back({position[i], t});
    }

    sort(arr.begin(), arr.end());

    int fleets = 0;
    double maxTime = 0;

    for(int i=n-1;i>=0;i--)
    {
        double t = arr[i].second;

        if(t > maxTime)
        {
            fleets++;
            maxTime = t;
        }
    }

    return fleets;
    }
};
