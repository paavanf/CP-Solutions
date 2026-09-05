class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n=nums.size();
        vector<int>pfMaxi(n),sfMini(n);
        pfMaxi[0]=nums[0];
        sfMini[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        pfMaxi[i]=max(pfMaxi[i-1],nums[i]);
        for(int i=n-2;i>=0;i--)
        sfMini[i]=min(nums[i],sfMini[i+1]);
        for(int i=0;i<n;i++)
        {
            int instable_score=pfMaxi[i]-sfMini[i];
            if(instable_score<=k)
            return i;
        }
        return -1;
    }
};