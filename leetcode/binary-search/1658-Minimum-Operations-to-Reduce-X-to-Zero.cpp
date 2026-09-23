class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sm=0;
        for(int i=0;i<n;i++)
        sm+=nums[i];
        int target=sm-x;
        if(target<0)
        return -1;
        if(target==0)
        return n;
        int l=0,s=0,maxiLen=-1;
        for(int r=0;r<n;r++)
        {
            s+=nums[r];
            while(s>target)
            {
                s-=nums[l];
                l++;
            }
            if(s==target)
            maxiLen=max(maxiLen,r-l+1);
        }
        if(maxiLen==-1)
        return -1;
        return n-maxiLen;
    }
};