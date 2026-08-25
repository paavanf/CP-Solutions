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
    void f(int r,vector<string>&board,int n,vector<vector<string>>&ans)
    {
        //base case
        if(r==n)
        {
            ans.push_back(board);
            return;
        }
        //check for every col
        for(int c=0;c<n;c++)
        {
            if(safe(board,r,c,n))
            {
                board[r][c]='Q';//queen placed
                f(r+1,board,n,ans);//move to next row
                //backtrack
                board[r][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        f(0,board,n,ans);
        return ans;
    }
};