class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0)
        return 0;
        grid[i][j]=0;
        int a=1;
        a+=dfs(i+1,j,grid);
        a+=dfs(i-1,j,grid);
        a+=dfs(i,j+1,grid);
        a+=dfs(i,j-1,grid);
        return a;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int area=dfs(i,j,grid);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};