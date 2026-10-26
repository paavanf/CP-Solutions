using ll=long long;
class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis,int kk)
    {
        vis[i][j]=1;
        int m=grid.size();
        int n=grid[0].size();
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        ll ans=grid[i][j];
        for(int k=0;k<4;k++)
        {
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(nr<0 || nr>=m || nc<0 || nc>=n || grid[nr][nc]==0 || vis[nr][nc])
            continue;
            ans+=dfs(nr,nc,grid,vis,kk);
        }
        return ans%kk;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        int ct=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0 || vis[i][j])
                continue;
                if(dfs(i,j,grid,vis,k)%k==0)
                ct++;
            }
        }
        return ct;
    }
};