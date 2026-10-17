class Solution {
public:
    void sort(int l, int m, int r, vector<int>& arr)
{
    int i = l;
    int j = m + 1;
    vector<int> temp;

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;  // left half used
        }
        else
        {
            temp.push_back(arr[j]);
            j++;  // right half used
        }
    }

    // Hint: copy remaining left-half elements
    while (i <= m)
    {
        // your code
        temp.push_back(arr[i]);
        i++;
    }

    // Hint: copy remaining right-half elements
    while (j <= r)
    {
        // your code
        temp.push_back(arr[j]);
        j++;
    }

    // Hint: copy temp back into arr, beginning at l
    int u=0;
    for(int k=l;k<=r;k++)
    {
        arr[k]=temp[u++];
    }
}
    void mergeSort(int l,int r,vector<int>& nums)
    {
        if(l>=r)
            return;
        int m=l+(r-l)/2;
        mergeSort(l,m,nums);
        mergeSort(m+1,r,nums);
        sort(l,m,r,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(0,n-1,nums);
        return nums;
        
    }
};