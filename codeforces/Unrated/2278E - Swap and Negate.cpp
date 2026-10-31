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
       {
        ll val;
        cin>>val;
        //parity indexing
        if(i%2==0)
        a[i]=-val;
        else
        a[i]=val;
       }
       sort(a.begin(),a.end());
       ll oddIdxCt=(n+1)/2;
       ll ts=0;
       //now smallest ele will go to odd posis
       for(int i=0;i<oddIdxCt;i++)
       ts-=a[i];
       for(int i=oddIdxCt;i<n;i++)
       ts+=a[i];
       cout<<ts<<endl;
    }
    return 0;
}