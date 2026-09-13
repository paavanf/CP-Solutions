class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pf) {
        int n=st.size();
        vector<vector<int>>jb(n,vector<int>(3));
        for(int i=0;i<n;i++)
        jb[i]={st[i],et[i],pf[i]};
        sort(jb.begin(),jb.end(),[](auto &a,auto &b)
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
            if(jb[mid][1]<=jb[i][0])
            {
                ans=mid;
                l=mid+1;
            }
            else
            h=mid-1;
            }
            prev[i]=ans;
        }
        vector<int>dp(n);
        dp[0]=jb[0][2];
        for(int i=1;i<n;i++)
        {
            int leave=dp[i-1];
            int take=jb[i][2];
            if(prev[i]!=-1)
            take+=dp[prev[i]];
            dp[i]=max(take,leave);
        }
        return dp[n-1];
    }
};