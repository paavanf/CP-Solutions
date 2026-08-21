using ll=long long;
//To count how many ugly numbers ≤ X, we use inclusion-exclusion principle:
//count = (X/a + X/b + X/c) - (X/lcm(a,b) + X/lcm(b,c) + X/lcm(a,c)) + (X/lcm(a,b,c)).
ll gcd(int a,int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
ll lcm(int a,int b)
{
    return (1LL *a/gcd(a,b))*b;
}
ll multiples(ll val,ll a,ll b,ll c)
{
    ll lcmAB=lcm(a,b);
    ll lcmBC=lcm(b,c);
    ll lcmAC=lcm(a,c);
    ll lcmABC=lcm(lcmAB,c);
    return (val/a+val/b+val/c-val/lcmAB-val/lcmBC-val/lcmAC+val/lcmABC);
}
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        ll s=1,e=2*1e9;
        while(s<=e)
        {
            ll mid=s+(e-s)/2;
            if(multiples(mid,(ll)a,(ll)b,(ll)c)>=n)
            e=mid-1;
            else
            s=mid+1;
        }
        return (int)s;
    }
};