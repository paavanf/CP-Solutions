using ll=long long;
class Solution {
public:
    long long maxEarnings(vector<vector<int>>& m) {
        int n=m.size();
        vector<vector<int>>e(n,vector<int>(3));
        for(int i=0;i<n;i++)
        {
            e[i]=m[i];
        }
        sort(e.begin(),e.end(),[](auto &a,auto &b)
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
            if(e[mid][1]<=e[i][0])
            {
                ans=mid;
                l=mid+1;
            }
            else
            h=mid-1;
            }
            prev[i]=ans;
        }
        vector<ll>dp(n),best(n);
        dp[0]=e[0][2];
        best[0]=dp[0]-e[0][1];
        for(int i=1;i<n;i++)
        {
            ll leave=dp[i-1];
            ll take=e[i][2];
            if(prev[i]!=-1)
            {
                take=max(take,(ll)e[i][2]+e[i][0]+best[prev[i]]);
            }
            dp[i]=max(take,leave);
            best[i]=max(best[i-1],dp[i]-e[i][1]);
        }
        return dp[n-1];
    }
};