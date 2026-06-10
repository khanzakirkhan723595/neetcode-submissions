class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int l=0;
        int r=n-1;
        int maxiw=INT_MIN;
        while(l<r)
        {
            int h=min(heights[l],heights[r]);
            int b=r-l;
            int water=h*b;
            maxiw=max(maxiw,water);
            if(heights[l]<heights[r])
                l++;
            else{
                r--;
            }
        }
        return maxiw;
        
    }
};
