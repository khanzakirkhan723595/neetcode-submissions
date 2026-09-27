class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int maxi=arr[n-1];
        int prev=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxi=max(maxi,arr[i]);
            arr[i]=prev;
            prev=maxi;
            
        }
        arr[n-1]=-1;
        return arr;
        
    }
};