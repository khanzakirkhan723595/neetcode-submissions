class Solution {
public:
int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            int a=search(matrix[i],target);
            if(a!=-1)
            {
                return true;
            }
            
           
        }
        return false;
        
    }
};
