#include <bits/stdc++.h>
using ll=long long;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       vector<ll>a(n);
       for(int i=0;i<n;i++)
       cin>>a[i];
       sort(a.begin(),a.end());
       ll Ops_mini=a[n-1]-a[0];
       ll Ops_med=a[n/2];
       ll Cost_mini=0;
       for(int i=0;i<n;i++)
       Cost_mini+=abs(a[i]-Ops_med);
       cout<<Cost_mini<<" "<<Ops_mini<<endl;
    }
    return 0;
}