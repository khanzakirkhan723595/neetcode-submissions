class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        int top=0;
        int left=0;
        int bottom=m-1;
        int right=n-1;
        vector<int>res;
        while(top<=bottom && left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                res.push_back(mat[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                res.push_back(mat[i][right]);
            }
            right--;
            if(top>bottom || left>right)
                break;
            for(int i=right;i>=left;i--)
            {
                res.push_back(mat[bottom][i]);
            }
            bottom--;
            for(int i=bottom;i>=top;i--)
            {
                res.push_back(mat[i][left]);
            }
            left++;

        }
        return res;
    }
};
