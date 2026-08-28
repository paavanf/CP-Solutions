class Solution {
public:
    int f(int amt,vector<int>&c,vector<int>&dp)
    {
        if(amt==0)
        return 0;
        if(dp[amt]!=-1)
        return dp[amt];
        int ans=INT_MAX;
        for(int cn:c)
        {
            if(amt>=cn)
            {
                int res=f(amt-cn,c,dp);
                if(res!=INT_MAX)
                ans=min(ans,res+1);
            }
        }
        return dp[amt]=ans;
    }
    int coinChange(vector<int>& c, int amt) {
        vector<int>dp(amt+1,-1);
        int ans=f(amt,c,dp);
        return ans==INT_MAX?-1:ans;
    }
};