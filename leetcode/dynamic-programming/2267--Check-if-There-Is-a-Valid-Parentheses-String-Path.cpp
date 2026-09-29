class Solution {
public:
    bool dfs(int i,int j,int bal,vector<vector<char>>& grid,vector<vector<vector<int>>>&dp)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[i][j]=='(')
        bal++;
        else
        bal--;
        if(bal<0)
        return false;
        if(i==m-1 && j==n-1)
        return bal==0;
        if(dp[i][j][bal]!=-1)
        return dp[i][j][bal];
        bool flag=false;
        //move down
        if(i+1<m)
        flag=flag || dfs(i+1,j,bal,grid,dp);
        //move right
        if(j+1<n)
        flag=flag || dfs(i,j+1,bal,grid,dp);
        return dp[i][j][bal]=flag;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //for paranthesis to match path length must be even
        if((m+n-1)%2!=0)
        return false;
        if(grid[0][0]==')')
        return false;
        if(grid[m-1][n-1]=='(')
        return false;
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(m+n,-1)));
        return dfs(0,0,0,grid,dp);
    }
};