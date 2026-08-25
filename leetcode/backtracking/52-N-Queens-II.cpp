class Solution {
public:
bool safe(vector<string>&board,int r,int c,int n)
    {
        //check that particular col
        for(int i=0;i<r;i++)
        {
            if(board[i][c]=='Q')
            return false;
        }
        //check upper left diag
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
            return false;
        }
        //check upper right
        for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++)
        {
            if(board[i][j]=='Q')
            return false;
        }
        return true;
    }
    int f(int r,vector<string>&board,int n)
    {
        //base case
        if(r==n)
        return 1;
        int ct=0;
        //check for every col
        for(int c=0;c<n;c++)
        {
            if(safe(board,r,c,n))
            {
                board[r][c]='Q';//queen placed
                ct+=f(r+1,board,n);//move to next row
                //backtrack
                board[r][c]='.';
            }
        }
        return ct;
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        return f(0,board,n);
    }
};