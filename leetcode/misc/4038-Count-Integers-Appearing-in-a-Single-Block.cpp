class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        mp[nums[0]]=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            mp[nums[i]]++;
        }
        int ct=0;
        for(auto &block:mp)
        {
            if(block.second==1)
            ct++;
        }
        return ct;
    }
};