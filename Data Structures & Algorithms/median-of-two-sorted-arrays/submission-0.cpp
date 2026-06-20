class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
          // Always binary search on smaller array
        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int n = nums1.size();
        int m = nums2.size();

        int total = n + m;
        int half = (total + 1) / 2;

        int l = 0;
        int r = n;

        while(l <= r)
        {
            int partitionA = l + (r - l) / 2;
            int partitionB = half - partitionA;

            int Aleft =
                (partitionA == 0)
                ? INT_MIN
                : nums1[partitionA - 1];

            int Aright =
                (partitionA == n)
                ? INT_MAX
                : nums1[partitionA];

            int Bleft =
                (partitionB == 0)
                ? INT_MIN
                : nums2[partitionB - 1];

            int Bright =
                (partitionB == m)
                ? INT_MAX
                : nums2[partitionB];

            // Valid partition found
            if(Aleft <= Bright && Bleft <= Aright)
            {
                // Odd number of elements
                if(total % 2 == 1)
                {
                    return max(Aleft, Bleft);
                }

                // Even number of elements
                return (max(Aleft, Bleft) +
                        min(Aright, Bright)) / 2.0;
            }

            // Took too many elements from A
            else if(Aleft > Bright)
            {
                r = partitionA - 1;
            }

            // Took too few elements from A
            else
            {
                l = partitionA + 1;
            }
        }

        return 0.0;
    }
};
