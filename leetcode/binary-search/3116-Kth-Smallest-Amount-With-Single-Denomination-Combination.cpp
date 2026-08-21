using ll=long long;
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
    ll ct(ll val,vector<int>& coins,int idx,int currLcm,int currCt)
    {
        int n=coins.size();
        if(idx==n)
        {
            if(currCt==0)
            return 0;
            if(currCt%2==1)
            return val/currLcm;
            else
            return -(val/currLcm);
        }
        ll notTake=ct(val,coins,idx+1,currLcm,currCt);
        ll newLcm=lcm((ll)coins[idx],currLcm);
        ll take=0;
        if(newLcm<=val)
        take=ct(val,coins,idx+1,newLcm,currCt+1);
        return take+notTake;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll s=1;
        ll e=LLONG_MAX;
        for(auto &x:coins)
        e=min(e,(ll)x);
        e*=k;
        while(s<=e)
        {
            ll mid=s+(e-s)/2;
            if(ct(mid,coins,0,1,0)>=k)
            e=mid-1;
            else
            s=mid+1;
        }
        return s;
    }
};