class Solution {
public:
    bool isSafe(int r,int c,vector<string> &board,int n)
    {
        //row
        for(int i=0;i<n;i++)
        {
            if(board[i][c]=='Q')
                return false;
        }
        //column
        for(int j=0;j<n;j++)
        {
            if(board[r][j]=='Q')
                return false;
        }
        //left diagonal
        for(int i=r,j=c;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        //left diagonal
        for(int i=r,j=c;i>=0 && j<n;i--,j++)
        {
            if(board[i][j]=='Q')
                return false;
        }
        return true;


    }
    void solve(int row,vector<string> &board,vector<vector<string>> & ans,int n)
    {
        if(row==n)
        {
            ans.push_back(board);
            return ;
        }
        for(int j=0;j<n;j++)
        {
            if(isSafe(row,j,board,n))
            {
                //choose
                board[row][j]='Q';
                solve(row+1,board,ans,n);
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0,board,ans,n);  
        return ans;      
    }
};
