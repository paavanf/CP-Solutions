using ll=long long;
const int mod=1e9+7;
class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<ll>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            ll ans=1;
            vector<bool>used(26,false);
            for(int j=i;j<n;j++)
            {
                if(!used[s[j]-'a'])
                {
                    used[s[j]-'a']=true;
                    ans=(ans+dp[j+1])%mod;
                }
            }
            dp[i]=ans;
        }
        return (dp[0]-1+mod)%mod;
    }
};