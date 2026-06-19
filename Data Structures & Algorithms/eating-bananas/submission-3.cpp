class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, piles[i]);
    }

    int l=1;
    int r=maxi-1;
    int ans=maxi;;
    while(l<=r)
    {
        int mid = (l+r)/2;
        int hours=0;
        for(int pile : piles)
        {
            hours+=(pile+mid-1)/mid;
        }
        if(hours<=h)
        {
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    
    return ans;
    }
};
