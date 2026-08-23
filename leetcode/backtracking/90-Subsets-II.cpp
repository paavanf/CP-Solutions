class Solution {
public:
    void f(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans)
    {
        int n=nums.size();
        if(idx==n)
        {
            ans.push_back(temp);
            return;
        }
        //take;
        temp.push_back(nums[idx]);
        f(idx+1,nums,temp,ans);
        temp.pop_back();
        //not take
        int i=idx+1;
        while(i<n && nums[i]==nums[idx])
        i++;
        f(i,nums,temp,ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        f(0,nums,temp,ans);
        return ans;
    }
};