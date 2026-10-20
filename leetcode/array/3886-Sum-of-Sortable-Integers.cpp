class Solution {
public:
    bool check(vector<int>&nums,int k)
    {
        int n=nums.size();
        int prev=0;//maximum ele of previous block
        for(int i=0;i<n;i+=k)
        {
            int ct=0;
            int mini=nums[i];
            int maxi=nums[i];
            for(int j=i;j<i+k-1;j++)
            {
                if(nums[j]>nums[j+1])
                ct++;
                mini=min(mini,nums[j+1]);
                maxi=max(maxi,nums[j+1]);
            }
            if(nums[i+k-1]>nums[i])
            ct++;
            if(ct>1 || prev>mini)
            return false;
            prev=maxi;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int k=1;k*k<=n;k++)//all divisors
        {
            if(n%k==0)
            {
                if(check(nums,k))
                ans+=k;
                if(k*k!=n && check(nums,n/k))
                ans+=n/k;
            }
        }
        return ans;
    }
};