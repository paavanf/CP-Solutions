using ll=long long;
using T=tuple<ll,int,int,int,int>;//cost,r,c,dir,turn
class Solution {
public:
    bool path(int r,int c,int m,int n)
    {
        return r>=0 && r<m && c>=0 && c<n;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==1 && n==1)
        return grid[0][0];
        vector<vector<vector<vector<ll>>>>dist(m,vector<vector<vector<ll>>>(n,vector<vector<ll>>(4,vector<ll>(k+1,LLONG_MAX))));
        priority_queue<T,vector<T>,greater<T>>pq;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        for(int i=0;i<4;i++)
        {
            int nr=dr[i];
            int nc=dc[i];
            if(!path(nr,nc,m,n))
            continue;
            ll cost=grid[0][0]+grid[nr][nc];
            dist[nr][nc][i][0]=cost;
            pq.push({cost,nr,nc,i,0});
        }
        while(!pq.empty())
        {
            auto[cost,r,c,prevDir,turns]=pq.top();
            pq.pop();
            if(cost!=dist[r][c][prevDir][turns])
            continue;
            if(r==m-1 && c==n-1)
            return cost;
            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(!path(nr,nc,m,n))
                continue;
                int newTurns=turns;
                if(i!=prevDir)
                newTurns++;
                if(newTurns>k)
                continue;
                ll newCost=cost+grid[nr][nc];
                if(newCost<dist[nr][nc][i][newTurns])
                {
                    dist[nr][nc][i][newTurns]=newCost;
                    pq.push({newCost,nr,nc,i,newTurns});
                }
            }
        }
        return -1;
    }
};