class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int miniIdx=0,maxiIdx=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<nums[miniIdx])
            miniIdx=i;
            if(nums[i]>nums[maxiIdx])
            maxiIdx=i;
        }
        if(miniIdx>maxiIdx)
        swap(miniIdx,maxiIdx);
        //removing all left onwards
        int left_del=maxiIdx+1;
        //removing all right onwards
        int right_del=n-miniIdx;
        //removing both ways
        int del=(miniIdx+1)+(n-maxiIdx);
        return min({left_del,right_del,del});
    }
};