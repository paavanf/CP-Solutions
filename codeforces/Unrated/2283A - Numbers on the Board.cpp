#include <bits/stdc++.h>
using ll=long long;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int l,r;
       cin>>l>>r;
       if(l>0 || r<0)
       cout<<r-l<<endl;
       else
       {
        int ans=abs(l+r);
        cout<<max(0,ans-1)<<endl;
       }
    }
    return 0;
}