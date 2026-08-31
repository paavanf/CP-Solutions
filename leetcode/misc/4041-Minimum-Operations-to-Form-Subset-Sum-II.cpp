using ll=long long;
class Solution {
public:
    int f(int idx,int sm,vector<int>&nums,vector<vector<int>>&dp)
    {
         if(sm==0)
            return 0;
        if(idx>=nums.size())
            return INT_MAX;
        if(dp[idx][sm]!=-1)
            return dp[idx][sm];
        int notTake=f(idx+1,sm,nums,dp);
        int take=INT_MAX;
        int n=nums[idx];
        int currOps=0;
        while(n>0)
        {
            int ops=currOps;
            int temp=n;
            while(temp<=sm)
            {
                int ans=f(idx+1,sm-temp,nums,dp);
                    if(ans!=INT_MAX)
                        take=min(take,ops+ans);
                temp*=2;
                ops++;
            }
            n/=2;
            currOps++;
        }
        return dp[idx][sm]=min(take,notTake);
    }
    int minOperations(vector<int>& nums, int sum) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int miniOps=INT_MAX;
        miniOps=f(0,sum,nums,dp);
        if(miniOps==INT_MAX)
            return -1;
        else
            return miniOps;
    }
};