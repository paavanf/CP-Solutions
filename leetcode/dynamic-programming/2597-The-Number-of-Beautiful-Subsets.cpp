class Solution {
public:
    int f(int idx,vector<int>& nums,int k,vector<int>&ans)
    {
        int n=nums.size();
        if(idx>=n)
        {
            if(!ans.empty())
            return 1;
            return 0;
        }
        //dont take
        int sol=f(idx+1,nums,k,ans);
        //take
        bool flag=true;
        for(int x:ans)
        {
            if(abs(x-nums[idx])==k)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            ans.push_back(nums[idx]);
            sol+=f(idx+1,nums,k,ans);
            ans.pop_back();
        }
        return sol;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int>ans;
        return f(0,nums,k,ans);
    }
};