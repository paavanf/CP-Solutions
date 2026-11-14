class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int ms=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int s=0;
            for(int j=i;j<n && j-i+1<=r;j++)
            {
                s+=nums[j];
                int k=j-i+1;
                if(k>=l && s>0)
                {
                    ms=min(ms,s);
                }
            }
        }
        if(ms!=INT_MAX)
        {
            return ms;
        }
        else{
            return -1;
        }
    }
};