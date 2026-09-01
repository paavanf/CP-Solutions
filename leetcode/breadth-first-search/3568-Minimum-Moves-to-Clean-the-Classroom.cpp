class Solution {
public:
    int minMoves(vector<string>& c, int e) {
        int m=c.size();
        int n=c[0].size();
        int sr,sc;
        int lc=0;
        //need info about the litters
        vector<vector<int>>ltr_idx(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(c[i][j]=='S')
                {
                    sr=i,sc=j;
                }
                if(c[i][j]=='L')
                {
                    ltr_idx[i][j]=lc;
                    lc++;
                }
            }
        }
        //represent litters in terms of setBits
        int ltrBits=(1<<lc)-1;
        //now keep track of the litters using bfs,to handle energy
        vector<vector<vector<int>>>eg(m,vector<vector<int>>(n,vector<int>(1<<lc,-1)));
        queue<array<int,5>>q;//(x,y,ltr_Bits,remEng,moves)
        q.push({sr,sc,0,e,0});
        eg[sr][sc][0]=e;
        //four directions
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty())
        {
            auto[x,y,lb,remEg,moves]=q.front();
            q.pop();
            if(lb==ltrBits)
            return moves;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                //base case
                if(nx<0 || ny<0 || nx>=m || ny>=n)
                continue;
                if(c[nx][ny]=='X')
                continue;
                int newEg=remEg-1;
                if(newEg<0)
                continue;
                int new_lb=lb;
                if(c[nx][ny]=='L')
                {
                    int l=ltr_idx[nx][ny];
                    //now mark this as collected
                    new_lb|=(1<<l);
                }
                if(c[nx][ny]=='R')
                {
                    newEg=e;
                }
                if(newEg<=eg[nx][ny][new_lb])
                continue;
                eg[nx][ny][new_lb]=newEg;
                q.push({nx,ny,new_lb,newEg,moves+1});
            }
        }
        return -1;
    }
};