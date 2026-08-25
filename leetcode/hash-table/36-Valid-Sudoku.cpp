class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row x digit
        vector<vector<bool>>r(9,vector<bool>(10,false));
        vector<vector<bool>>c(9,vector<bool>(10,false));
        vector<vector<bool>>b(9,vector<bool>(10,false));
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                continue;
                int n=board[i][j]-'0';
                //which 3x3 box
                int box=(i/3)*3+(j/3);
                if(r[i][n] || c[j][n] || b[box][n])
                return false;
                r[i][n]=true;
                c[j][n]=true;
                b[box][n]=true;
            }
        }
        return true;
    }
};