using ll=long long;
const int mod=1e9+7;
class Solution {
public:
    map<vector<int>,ll>mp;
    ll f(vector<int>&nums,vector<vector<ll>>&dp)
    {
        int n=nums.size();
        if(n<=2)
        return 1;
        if(mp.find(nums)!=mp.end())
        return mp[nums];
        vector<int>l,r;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[0])
            l.push_back(nums[i]);
            else
            r.push_back(nums[i]);
        }
        ll ways=dp[n-1][l.size()];
        ways=ways*f(l,dp)%mod;
        ways=ways*f(r,dp)%mod;
        return mp[nums]=ways;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=dp[i][i]=1;
            for(int j=1;j<i;j++)
            {
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
            }
        }
        return (f(nums,dp)-1+mod)%mod;
    }
};