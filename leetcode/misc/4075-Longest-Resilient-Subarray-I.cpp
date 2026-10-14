using ll=long long;
class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxLen=1;//single ele
        for(int i=0;i<n;i++)
        {
            int r=nums[i]%k;//req common remainder
            int sm=nums[i];//sum of subarray
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]%k!=r)
                break;
                ll len=j-i+1;
                sm+=nums[j];
                if((sm%k)==r)
                maxLen=max(maxLen,(int)len);
            }
        }
        return maxLen;
    }
};