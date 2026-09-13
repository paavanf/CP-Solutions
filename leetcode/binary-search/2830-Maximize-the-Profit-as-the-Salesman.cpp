class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
         int m=offers.size();
        vector<vector<int>>pf(m,vector<int>(3));
        for(int i=0;i<m;i++)
        pf[i]=offers[i];
        sort(pf.begin(),pf.end(),[](auto &a,auto &b)
        {
            return a[1]<b[1];
        });
        vector<int>prev(m);
        for(int i=0;i<m;i++)
        {
            int l=0,h=i-1,ans=-1;
            while(l<=h)
            {
            int mid=l+(h-l)/2;
            if(pf[mid][1]<pf[i][0])
            {
                ans=mid;
                l=mid+1;
            }
            else
            h=mid-1;
            }
            prev[i]=ans;
        }
        vector<int>dp(m);
        dp[0]=pf[0][2];
        for(int i=1;i<m;i++)
        {
            int leave=dp[i-1];
            int take=pf[i][2];
            if(prev[i]!=-1)
            take+=dp[prev[i]];
            dp[i]=max(take,leave);
        }
        return dp[m-1];
    }
};