class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int l=0;
        int r=0;
        int maxArea=0;
        for(int i=0;i<n;i++)
{
    int minh=INT_MAX;

    for(int j=i;j<n;j++)
    {
        minh=min(minh,heights[j]);

        maxArea=max(maxArea,minh*(j-i+1));
    }
}
        return maxArea;
        
    }
};
