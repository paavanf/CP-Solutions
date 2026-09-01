class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int sr,sc;
        int kc=0;
        //characters already tell us the index
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='@')
                {
                    sr=i,sc=j;
                }
                if(grid[i][j]>='a' && grid[i][j]<='z')
                {
                    kc++;
                }
            }
        }
        int keyBits=(1<<kc)-1;
        vector<vector<vector<bool>>>vis(m,vector<vector<bool>>(n,vector<bool>(1<<kc,false)));
        queue<array<int,3>>q;
        q.push({sr,sc,0});
        vis[sr][sc][0]=true;
        int moves=0;
        //four directions
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto[x,y,kb]=q.front();
                q.pop();
                if(kb==keyBits)
                return moves;
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<0 || ny<0 || nx>=m || ny>=n)
                    continue;
                    char cell=grid[nx][ny];
                    if(cell=='#')
                    continue;
                    int new_kb=kb;
                    //if it is a lock
                    if(cell>='A' && cell<='F')
                    {
                        int lock_idx=cell-'A';
                        //cannot pass without corresponding key
                        if((kb&(1<<lock_idx))==0)
                        continue;
                    }
                    //if it is a key
                    if(cell>='a' && cell<='f')
                    {
                        int key_idx=cell-'a';
                        //collect the key
                        new_kb|=(1<<key_idx);
                    }
                    if(vis[nx][ny][new_kb])
                    continue;
                    vis[nx][ny][new_kb]=true;
                    q.push({nx,ny,new_kb});
                }

            }
            moves++;
        }
        return -1;
    }
};