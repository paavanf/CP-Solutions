class Solution {
public:
    int check(int i,int j,vector<vector<int>>&grid){
        int cnt=0;
        int dx[4]={0,-1,0,1};
        int dy[4]={-1,0,1,0};

        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];

            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]==0) cnt++;

            else if(x<0 || x>=grid.size() || y>=grid[0].size() || y<0) cnt++;

            else continue;
        }
        return cnt;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans+=check(i,j,grid);
                }
            }
        }
        return ans;
    }
};