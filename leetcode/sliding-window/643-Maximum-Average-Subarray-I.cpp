class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sm=0;
        for(int i=0;i<k;i++)
        sm+=nums[i];
        int maxi=sm;
        for(int i=k;i<nums.size();i++)
        {
            sm+=nums[i];
            sm-=nums[i-k];
            maxi=max(maxi,sm);
        }
        return (double)maxi/k;
    }
};