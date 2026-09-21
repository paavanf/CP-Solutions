#include <bits/stdc++.h>
using ll=long long;
using namespace std;
const int inf=200005;
//precomputing prime factors
void pf(vector<int>&pd,int upperLimit)
{
    for(int i=2;i<upperLimit;i++)
    {
        pd[i]=i;
    }
    for(int i=2;i*i<upperLimit;i++)
    {
        if(pd[i]==i)
        {
            for(int j=i*i;j<upperLimit;j+=i)
            {
                if(pd[j]==j)
                pd[j]=i;
            }
        }
    }
}
ll f(int num,int k,vector<ll>&dp,vector<int>&pd)
{
    //base case
    if(num<=k)
    return 0;
    if(dp[num]!=-1)
    return dp[num];
    ll miniOps=1e18;
    int t=num;
    while(t>1)
    {
        int p=pd[t];
        ll currOps=1+(ll)p*f(num/p,k,dp,pd);
        miniOps=min(miniOps,currOps);
        while(t%p==0)
        t/=p;
    }
    return dp[num]=miniOps;
}
int main()
{
    vector<int>pd(inf);
    pf(pd,inf);
    int t;
    cin>>t;
    while(t--)
    {
       int n,k;
       cin>>n>>k;
       vector<int>a(n);
       int maxi=0;
       for(int i=0;i<n;i++)
       {
        cin>>a[i];
        maxi=max(maxi,a[i]);
       }
       vector<ll>dp(maxi+1,-1);
       ll ops=0;
       for(int i=0;i<n;i++)
       ops+=f(a[i],k,dp,pd);
       cout<<ops<<endl;
    }
    return 0;
}