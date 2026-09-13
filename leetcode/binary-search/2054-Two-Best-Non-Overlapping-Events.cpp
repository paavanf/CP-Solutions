class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& ev) {
        int n=ev.size();
        vector<vector<int>>ea(n,vector<int>(3));
        for(int i=0;i<n;i++)
        ea[i]=ev[i];
        sort(ea.begin(),ea.end(),[](auto &a,auto &b)
        {
            return a[1]<b[1];
        });
        vector<int>prev(n);
        for(int i=0;i<n;i++)
        {
            int l=0,h=i-1,ans=-1;
            while(l<=h)
            {
            int mid=l+(h-l)/2;
            if(ea[mid][1]<ea[i][0])
            {
                ans=mid;
                l=mid+1;
            }
            else
            h=mid-1;
            }
            prev[i]=ans;
        }
        vector<vector<int>>dp(n+1,vector<int>(2+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2;j++)
            {
                int leave=dp[i-1][j];
                int take=ea[i-1][2];
                int p=prev[i-1];
                if(p!=-1)
                take+=dp[p+1][j-1];
                dp[i][j]=max(take,leave);
            }
        }
        return dp[n][2];
    }
};