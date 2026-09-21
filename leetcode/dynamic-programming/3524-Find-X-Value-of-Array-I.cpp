//1st way by not directly storing all the subarrays
using ll=long long;
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<ll>ans(k);
        int fq[5]={0};//no of subarrays ending at the prev position whose product %k=x
        for(int n:nums)
        {
            n%=k;
            int currFq[5]={0};
            currFq[n]=1;
            //get all prev subarrays
            for(int x=0;x<k;x++)
            {
                currFq[x*n%k]+=fq[x];
            }
            //add up the fq
            for(int x=0;x<k;x++)
            {
                fq[x]=currFq[x];
                ans[x]+=fq[x];
            }
        }
        return ans;

    }
};