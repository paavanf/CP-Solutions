class Solution {
public:
    void f(int idx,vector<int>& nums,vector<vector<int>>&ans)
    {
        int n=nums.size();
        if(idx==n)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            //skip dupli
            bool flag=false;
            for(int j=idx;j<i;j++)
            {
                if(nums[j]==nums[i])
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
            continue;
            swap(nums[idx],nums[i]);
            f(idx+1,nums,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        f(0,nums,ans);
        return ans;
    }
};