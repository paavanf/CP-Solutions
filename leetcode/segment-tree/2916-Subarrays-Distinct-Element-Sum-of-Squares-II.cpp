class Solution {
public:
    int sumCounts(vector<int>& nums) 
    {
        int MOD=1e9+7,n=nums.size(),ans=0;
        vector<long long> a(n+1),b(n+1);
        unordered_map<int,int> m;
        for (int i=0;i<n;i++) 
        {
            auto x=m.find(nums[i]);
            int y=(x==m.end())?-1:x->second;
            long long z=0,c=0;
            for (int j=n-y-1;j>0;j-=j & -j) 
            {
                z+=a[j];
                c+=b[j];
            }
            long long p=1LL*(i-y)*(i-y)-2*(c-y*z);
            ans=(ans+1LL*(n-i)*p)%MOD;
            for (int j=n-y;j<=n;j+=j & -j) 
            {
                a[j]++;
                b[j]+=y;
            }
            m[nums[i]] = i;  
        }  
        return (ans+MOD)%MOD;
    }
};