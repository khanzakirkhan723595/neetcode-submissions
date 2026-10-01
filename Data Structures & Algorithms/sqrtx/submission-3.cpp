class Solution {
public:
    int mySqrt(int x) {
    // Handle edge cases for 0 and 1
    if (x == 0 || x == 1) {
        return x;
    }
    
    int l = 1;
    int r = x;
    int res = 0;
    
    while (l <= r) {
        long long  mid = l + (r - l) / 2;
        if (mid*mid <= x) {
            res = mid;     
            l = mid + 1;   
        } else {
            r = mid - 1;   
        }
    }
    
    return res;
}
};