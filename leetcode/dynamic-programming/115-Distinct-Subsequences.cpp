class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(m+1,0));
        for(int i=0;i<=n;i++)
        dp[i][m]=1;
        //go backwards
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                unsigned long long notTake=dp[i+1][j];
                unsigned long long take=0;
                if(s[i]==t[j])
                take=dp[i+1][j+1];
                dp[i][j]=notTake+take;
            }
        }
        return dp[0][0];
    }
};