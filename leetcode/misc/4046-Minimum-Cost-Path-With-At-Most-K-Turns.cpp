class Solution {
public:
    bool path(int r,int c,int m,int n)
    {
        return r>=0 && r<m && c>=0 && c<n;
    }
    int f(int i,int j,int turns,int prevDir,vector<vector<int>>&grid,vector<vector<vector<vector<int>>>>&dp)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(!path(i,j,m,n))
        return INT_MAX;
        if(turns<0)
        return INT_MAX;
        if(i==m-1 && j==n-1)
        return grid[i][j];
        if(dp[i][j][turns][prevDir]!=-1)
        return dp[i][j][turns][prevDir];
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        int ans=INT_MAX;
        for(int x=0;x<4;x++)
        {
            int newTurns=turns;
            if(prevDir!=4 && x!=prevDir)
            newTurns--;
            int nr=i+dr[x];
            int nc=j+dc[x];
            int nextCost=f(nr,nc,newTurns,x,grid,dp);
            if(nextCost!=INT_MAX)
            ans=min(ans,grid[i][j]+nextCost);
        }
        return dp[i][j][turns][prevDir]=ans;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<vector<int>>>>dp(m,vector<vector<vector<int>>>(n,vector<vector<int>>(k+1,vector<int>(5,-1))));
        int ans=f(0,0,k,4,grid,dp);
        if(ans==INT_MAX)
        return -1;
        return ans;
    }
};