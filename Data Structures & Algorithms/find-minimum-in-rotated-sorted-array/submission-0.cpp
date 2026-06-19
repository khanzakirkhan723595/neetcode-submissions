class Solution {
public:
    int findMin(vector<int> &arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        int ans=INT_MAX;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(mid<n &&  arr[l]<=arr[mid])
            {
                ans=min(ans,arr[l]);
                l=mid+1;

            }
            else if(mid<n && arr[mid]<=arr[r])
            {
                ans=min(ans,arr[mid]);
                r=mid-1;
            }
        }
        return ans;
        
    }
};
