class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Sort the subrange in ascending order first
        //sort(vec.begin() + i, vec.begin() + j + 1);

        // Reverse the sorted subrange to get descending order
        //reverse(vec.begin() + i, vec.begin() + j + 1);
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.begin()+n);
        
    }
};