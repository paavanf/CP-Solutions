class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>dp;
        int ans=0;
        for(int n:nums)
        {
            int oldVal=dp[n];
            dp[n]=max(dp[n],dp[n-1]+1);//keeping n unchanged
            // Change x into x + 1.
            // Previous selected value must be x.
            // Use 'old' because the current element
            // cannot be used twice.
            dp[n+1]=max(dp[n+1],oldVal+1);
            ans=max({ans,dp[n],dp[n+1]});
        }
        return ans;
    }
};