class Solution {
public:
    bool isRow(int r,int c,int target,int n, vector<vector<char>>&nums)
    {
        for(int k=0;k<n;k++)
        {
            if(nums[r][k]==target && c!=k)
            {
                return true;
            }
        }
        return false;

    }
    bool isCol(int ro,int co,int target,int m, vector<vector<char>>&nums)
    {
        for(int k=0;k<m;k++)
        {
            if(nums[k][co]==target && ro!=k)
            {
                return true;
            }
        }
        return false;

    }
    bool isBox(int row,int col,char target,
           vector<vector<char>>& nums)
{
    int sr = (row/3)*3;
    int sc = (col/3)*3;

    for(int i=sr;i<sr+3;i++)
    {
        for(int j=sc;j<sc+3;j++)
        {
            if(nums[i][j]==target &&
               (i!=row || j!=col))
            {
                return true;
            }
        }
    }

    return false;
}
    bool isValidSudoku(vector<vector<char>>& nums) {
        int m=nums.size();
        int n=nums[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                char target=nums[i][j];

                // Skip empty cells
                if(target=='.')
                    continue;
                if(isRow(i,j,target,n,nums))
                {
                    return false;
                }
                else if(isCol(i,j,target,m,nums))
                {
                    return false;
                }
                else if(isBox(i,j,target,nums))
                {
                    return false;
                }


            }
        }
        return true;
        
    }
};
