using ll=long long;
const int mod=1e9+7;
class Solution {
public:
    int f(int i,string &s,vector<int>&dp)
    {
        int n=s.size();
        //if only empty seq remains
        if(i==n)
        return 1;
        if(dp[i]!=-1)
        return dp[i];
        ll ans=1;//empty subseq
        vector<bool>used(26,false);
        for(int j=i;j<n;j++)
        {
            //use only first occurence of each and every character
            if(!used[s[j]-'a'])
            {
                used[s[j]-'a']=true;
                ans=(ans+f(j+1,s,dp))%mod;
            }
        }
        return dp[i]=ans;
    }
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return (f(0,s,dp)-1+mod)%mod;//subtracting the empty subsequence
    }
};