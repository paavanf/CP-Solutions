class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=1,ct=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {
                if(ct<2)
                {
                    nums[k]=nums[i];
                    k++;
                    ct++;
                }
            }
            else
            {
                nums[k]=nums[i];
                k++;
                ct=1;
            }
        }
        return k;
    }
};