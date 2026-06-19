class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, piles[i]);
    }

    for(int k = 1; k <= maxi; k++) {

        long long cnt = 0;

        for(int j = 0; j < n; j++) {
            cnt += (piles[j] + k - 1) / k;
        }

        if(cnt <= h) {
            return k;
        }
    }

    return -1;
    }
};
