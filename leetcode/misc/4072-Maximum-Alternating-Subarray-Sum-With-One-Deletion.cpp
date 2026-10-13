using ll=long long;
class Solution {
public:
    ll f(int i,int sign,int delUsed,vector<int>&nums,vector<vector<vector<ll>>>&dp)
    {
        int n=nums.size();
        if(i==n)
        return 0;
        if(dp[i][sign][delUsed]!=LLONG_MIN)
        return dp[i][sign][delUsed];
        ll ans=0;
        ll currVal=0;
        if(sign==0)
        currVal=nums[i];
        else
        currVal=-1LL*nums[i];
        ll nextSign=1-sign;
        //take current ele
        ll take=currVal+f(i+1,nextSign,delUsed,nums,dp);
        ans=max(ans,take);
        //delete
        if(delUsed==0)
        {
            ll notTake=f(i+1,sign,1,nums,dp);
            ans=max(ans,notTake);
        }
        return dp[i][sign][delUsed]=ans;

    }
    long long maxAlternatingSum(vector<int>& nums) {
        //maximum alternating sum of subarray
        //kadanes
        //important part is that when we delete an element, the signs of the elements after it can change because the remaining subarray is reindexed from zero.
        //need to keep track of whether we have deleted an element or not and also the parity of each of them
        //intuition of DP
        //whether to start from here or not
        //whether to extend or not
        //whether to skip this or not,depending on whether we have deleted or not
        int n=nums.size();
        vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(2,vector<ll>(2,LLONG_MIN)));
        //currIdx,currSign(0 for +,1 for -),delUsed
        ll ans=LLONG_MIN;
        int i=0;
        while(i<n)
        {
            ll curr=nums[i]+f(i+1,1,0,nums,dp);
            ans=max(ans,curr);
            i++;
        }
        return ans;

    }
};