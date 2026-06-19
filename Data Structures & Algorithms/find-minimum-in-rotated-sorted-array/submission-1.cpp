class Solution {
public:
    int findMin(vector<int> &arr) {
        int l = 0;
    int r = arr.size() - 1;
    int ans = INT_MAX;

    while (l <= r) {

        // Entire range sorted
        if (arr[l] <= arr[r]) {
            ans = min(ans, arr[l]);
            break;
        }

        int mid = l + (r - l) / 2;

        // Left half sorted
        if (arr[l] <= arr[mid]) {
            ans = min(ans, arr[l]);
            l = mid + 1;
        }
        else { // Right half sorted
            ans = min(ans, arr[mid]);
            r = mid - 1;
        }
    }

    return ans;
    }
};
