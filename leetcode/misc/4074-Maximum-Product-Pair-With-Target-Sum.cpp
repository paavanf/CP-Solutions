class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        mp[nums[i]].push_back(i);
        int maxP=INT_MIN;
        vector<int>ans={-1,-1};
        for(int i=0;i<n;i++)
        {
            int x=target-nums[i];
            if(mp.find(x)!=mp.end() && nums[i]>x)
            {
                for(int idx:mp[x])
                {
                    if(idx!=i)
                    {
                        int p=nums[i]*x;
                        if(p>maxP)
                        {
                            maxP=p;
                            ans={i,idx};
                        }
                    }
                }
            }
        }
        return ans;
    }
};