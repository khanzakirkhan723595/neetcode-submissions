class Solution {
public:
    bool f(int i, int j, vector<vector<char>>& board,
       string word, string s)
{
    if(i < 0 || j < 0 ||
       i >= board.size() || j >= board[0].size())
        return false;

    if(board[i][j] == '#')
        return false;

    string ns1 = s + board[i][j];

    if(ns1 == word)
        return true;

    if(ns1.size() >= word.size())
        return false;

    char temp = board[i][j];
    board[i][j] = '#';

    if(f(i, j+1, board, word, ns1))
        return true;

    if(f(i+1, j, board, word, ns1))
        return true;

    if(f(i-1, j, board, word, ns1))
        return true;

    if(f(i, j-1, board, word, ns1))
        return true;

    board[i][j] = temp;

    return false;
}

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(f(i,j,board,word,""))
                    return true;
            }
        }

        return false;
    }
};