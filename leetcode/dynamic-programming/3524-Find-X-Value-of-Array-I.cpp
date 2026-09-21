//2nd way through Dp
using ll=long long;
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<ll>ans(k,0);
        vector<ll>dp(k,0);
        for(int n:nums)
        {
            int rem=n%k;
            vector<ll>newDp(k,0);
            newDp[rem]++;
            for(int x=0;x<k;x++)
            {
                int newRem=(x*rem)%k;
                newDp[newRem]+=dp[x];
            }
            for(int x=0;x<k;x++)
            {
                ans[x]+=newDp[x];
            }
            dp=newDp;
        }
        return ans;
    }
};