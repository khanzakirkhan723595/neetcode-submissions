class MedianFinder {
public:
    vector<int> nums;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
        
    }
    
    double findMedian() {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n%2==1)
        {
            return nums[n/2];
        }
        else{
            int m=n/2;
            if(m-1>=0)
            {
                return double((nums[m-1]+nums[m])/2.0);
            }
        }
        
    }
};
