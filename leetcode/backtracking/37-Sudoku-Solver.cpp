class Solution {
public:
    bool safe(vector<vector<char>>& board,int r,int c,char ch)
    {
        //check col
        for(int i=0;i<9;i++)
        {
            if(board[r][i]==ch)
            return false;
        }
        //check row
        for(int i=0;i<9;i++)
        {
            if(board[i][c]==ch)
            return false;
        }
        //check the boxes
        int nr=(r/3)*3;
        int nc=(c/3)*3;
        for(int i=nr;i<nr+3;i++)
        {
            for(int j=nc;j<nc+3;j++)
            {
                if(board[i][j]==ch)
                return false;
            }
        }
        return true;
    }
    bool f(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(safe(board,i,j,c))
                        {
                            board[i][j]=c;
                            if(f(board))
                            return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};