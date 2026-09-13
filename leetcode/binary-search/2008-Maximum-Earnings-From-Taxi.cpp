using ll=long long;
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
         int m=rides.size();
        vector<vector<ll>>taxi(m,vector<ll>(3));
        for(int i=0;i<m;i++)
        {
            ll st=rides[i][0];
            ll et=rides[i][1];
            ll tip=rides[i][2];
            taxi[i]={st,et,et-st+tip};
        }
        sort(taxi.begin(),taxi.end(),[](auto &a,auto &b)
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
            if(taxi[mid][1]<=taxi[i][0])
            {
                ans=mid;
                l=mid+1;
            }
            else
            h=mid-1;
            }
            prev[i]=ans;
        }
        vector<ll>dp(m);
        dp[0]=taxi[0][2];
        for(int i=1;i<m;i++)
        {
            ll leave=dp[i-1];
            ll take=taxi[i][2];
            if(prev[i]!=-1)
            take+=dp[prev[i]];
            dp[i]=max(take,leave);
        }
        return dp[m-1];
    }
};