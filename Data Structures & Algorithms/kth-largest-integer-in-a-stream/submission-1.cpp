class KthLargest {
public:
    vector<int> arr;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();i++)
        {
            arr.push_back(nums[i]);

        }

        
    }
    
    int add(int val) {
        arr.push_back(val);
        sort(arr.begin(),arr.end());
        return arr[arr.size()-k];


        
    }
};
