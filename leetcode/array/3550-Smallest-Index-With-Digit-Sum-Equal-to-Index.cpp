class Solution {
public:
    int digiSum(int x)
    {
        int s=0;
        while(x>0)
        {
            int d=x%10;
            s+=d;
            x/=10;
        }
        return s;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(digiSum(nums[i])==i)
            return i;
        }
        return -1;
    }
};