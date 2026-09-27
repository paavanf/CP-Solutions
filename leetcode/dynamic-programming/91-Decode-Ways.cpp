class Solution {
public:
    int f(int i,string &s,vector<int>&dp)
    {
        int n=s.size();
        if(i==n)
        return 1;
        if(s[i]=='0')
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int take1d=f(i+1,s,dp);
        int take2d=0;
        if(i+1<n)
        {
            int num=(s[i]-'0')*10+(s[i+1]-'0');
            if(num>=10 && num<=26)
            take2d=f(i+2,s,dp);
        }
        return dp[i]=take1d+take2d;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return f(0,s,dp);
    }
};