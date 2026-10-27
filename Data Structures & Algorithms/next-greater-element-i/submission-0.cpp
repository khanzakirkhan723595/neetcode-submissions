class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> nge(n1,-1);
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(nums2[j]==nums1[i])
                {
                    while(j<n2)
                    {
                        if(nums2[j]>nums1[i])
                        {
                            nge[i]=nums2[j];
                            break;
                        }
                        j++;
                    }
                }
            }
        }
        return nge;
        
    }
};