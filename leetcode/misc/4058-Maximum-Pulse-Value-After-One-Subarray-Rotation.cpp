using ll=long long;
class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n=nums.size();
        ll pulseVal=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            pulseVal+=nums[i];
            else
            pulseVal-=nums[i];
        }
        ll best=0,currSum=0;
        for(int i=0;i+1<n;i+=2)
        {
            ll x=nums[i]-nums[i+1];
            //kadane for min sum
            currSum=min(x,currSum+x);
            best=min(best,currSum);
        }
        currSum=0;
        for(int i=1;i+1<n;i+=2)
        {
            ll x=nums[i+1]-nums[i];
            currSum=min(x,currSum+x);
            best=min(best,currSum);
        }
        return pulseVal-2*best;
    }
};