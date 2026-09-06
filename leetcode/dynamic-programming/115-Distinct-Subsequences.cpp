class Solution {
public:
    int f(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
        int n=s.size();
        int m=t.size();
        if(j==m)
        return 1;
        if(i==n)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int notTake=f(i+1,j,s,t,dp);
        int take=0;
        if(s[i]==t[j])
        take=f(i+1,j+1,s,t,dp);
        return dp[i][j]=take+notTake;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,s,t,dp);
    }
};