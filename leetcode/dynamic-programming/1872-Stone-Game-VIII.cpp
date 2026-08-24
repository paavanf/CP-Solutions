class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>pref(n,0);
        pref[0]=stones[0];
        for(int i=1;i<n;i++)
        pref[i]=pref[i-1]+stones[i];
        vector<int>dp(n);
        //base case
        dp[n-2]=pref[n-1];
        for(int i=n-3;i>=0;i--)
        {
            int alice=dp[i+1];
            int bob=pref[i+1]-dp[i+1];
            dp[i]=max(alice,bob);
        }
        return dp[0];
    }
};