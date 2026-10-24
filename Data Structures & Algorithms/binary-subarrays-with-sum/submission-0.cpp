class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int l = 0, sum = 0, cnt = 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (sum > k) {
                sum -= nums[l];
                l++;
            }

            cnt += r - l + 1;
        }

        return cnt;
    }
};