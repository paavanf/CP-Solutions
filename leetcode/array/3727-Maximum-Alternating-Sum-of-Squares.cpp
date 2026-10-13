using ll=long long;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        for(int i=0;i<n;i++)
        nums[i]=abs(nums[i]);
        sort(nums.rbegin(),nums.rend());
        ll maxiScore=0;
        while(l<=r)
        {
            if(l==r)
            maxiScore+=nums[l]*nums[l];
            ll temp1=(nums[r]*nums[r]);
            ll temp2=(nums[l]*nums[l]);
            maxiScore+=temp2-temp1;
            l++;
            r--;
        }
        return maxiScore;
    }
};