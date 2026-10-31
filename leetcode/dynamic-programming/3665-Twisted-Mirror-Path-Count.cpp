using ll=long long;
const int mod=1e9+7;
class Solution {
public:
    int dfs(int i,int j,int direction,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n)
        return 0;
        if(i==m-1 && j==n-1)
        return 1;
        if(dp[i][j][direction]!=-1)
        return dp[i][j][direction];
        ll pathCt=0;
        if(grid[i][j]==0)
        {
            //move right
            pathCt+=dfs(i,j+1,0,grid,dp);
            //move down
            pathCt+=dfs(i+1,j,1,grid,dp);
        }
        else
        {
            //right ka mirror
            if(direction==0)
            pathCt+=dfs(i+1,j,1,grid,dp);
            //down ka mirror
            else
            pathCt+=dfs(i,j+1,0,grid,dp);
        }
        return dp[i][j][direction]=pathCt%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(2,-1)));
        ll pathCt=0;
        if(n>1)
        pathCt+=dfs(0,1,0,grid,dp);
        if(m>1)
        pathCt+=dfs(1,0,1,grid,dp);
        return pathCt%mod;
    }
};