class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0, sum = 0, cnt = 0;
        int prefixZeros = 0;

        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (l < r && (sum > goal || nums[l] == 0)) {
                if (sum > goal) {
                    sum -= nums[l];
                    l++;
                    prefixZeros = 0;
                } else {
                    prefixZeros++;
                    l++;
                }
            }

            if (sum == goal) {
                cnt += prefixZeros + 1;
            }
        }

        return cnt;
    }
};