class Solution {
public:
    int f(int s,int e,vector<int>& nums,vector<int>&dp)
    {
        if(s==e)
        return nums[s];
        if(s>e)
        return 0;
        if(dp[s]!=-1)
        return dp[s];
        int take=nums[s]+f(s+2,e,nums,dp);
        int notTake=0+f(s+1,e,nums,dp);
        return dp[s]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        //case1:dont rob first house
        vector<int>dp1(n,-1);
        int c1=f(1,n-1,nums,dp1);
        //case2:dont rob last house
        vector<int>dp2(n,-1);
        int c2=f(0,n-2,nums,dp2);
        return max(c1,c2);
    }
};