class Solution {
public:
    int f(int i,vector<int>&costs,vector<int>&dp)
    {
        if(i==0)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int miniTC=INT_MAX;
        if(i>=1)
        {
            int j=1;//jump
            miniTC=min(miniTC,f(i-1,costs,dp)+costs[i-1]+j*j);
        }
        if(i>=2)
        {
            int j=2;
            miniTC=min(miniTC,f(i-2,costs,dp)+costs[i-1]+j*j);
        }
        if(i>=3)
        {
            int j=3;
            miniTC=min(miniTC,f(i-3,costs,dp)+costs[i-1]+j*j);
        }
        return dp[i]=miniTC;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return f(n,costs,dp);
    }
};