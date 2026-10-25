class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis)
    {
        vis[i][j]=1;
        int m=grid.size();
        int n=grid[0].size();
        bool isClosed=true;
        if(i==0 || i==m-1 || j==0 || j==n-1)
        isClosed=false;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        for(int k=0;k<4;k++)
        {
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(nr<0 || nr>=m || nc<0 || nc>=n || grid[nr][nc]==1 || vis[nr][nc])
            continue;
            if(!dfs(nr,nc,grid,vis))
            isClosed=false;
        }
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        int ct=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 || vis[i][j])
                continue;
                if(dfs(i,j,grid,vis))
                ct++;
            }
        }
        return ct;
    }
};