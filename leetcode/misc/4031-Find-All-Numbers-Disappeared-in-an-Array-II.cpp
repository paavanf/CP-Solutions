class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(auto &x:nums)
        {
            if(x<lower)
            continue;
            if(x>upper)
            break;
            if(lower<x)
            ans.push_back({lower,x-1});
            lower=x+1;
        }
        if(lower<=upper)
        ans.push_back({lower,upper});
        return ans;
    }
};