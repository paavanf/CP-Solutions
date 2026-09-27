class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n=nums.size();
        map<pair<int,int>,int>mp;
        int currEP=0,maxiEP=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            currEP++;
            else
            {
                //(x,y) & (y,x)
                mp[{nums[i],nums[i-1]}]++;
                mp[{nums[i-1],nums[i]}]++;
            }
        }
        for(auto &it:mp)
        {
            maxiEP=max(maxiEP,it.second);
        }
        return currEP+maxiEP;
    }
};