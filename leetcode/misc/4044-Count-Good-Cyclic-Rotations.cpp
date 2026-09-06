using ll=long long;
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        int wz=n/2;
        ll ts=0,ws=0;
        for(int i=0;i<n;i++)
        ts+=nums[i];
        for(int i=0;i<wz;i++)
        ws+=nums[i];
        int grCt=0;
        for(int i=0;i<n;i++)
        {
            if(ws>ts-ws)
            grCt++;
            //remove
            ws-=nums[i];
            //add
            ws+=nums[(i+wz)%n];
        }
        return grCt;
    }
};