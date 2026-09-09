using ll=long long;
class Solution {
public:
    long long countCommas(long long n) {
        ll p=1000,ans=0;
        while(p<=n)
        {
            ans+=n-p+1;
            p*=1000;
        }
        return ans;
    }
};