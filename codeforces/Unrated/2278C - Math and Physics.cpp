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
       vector<int>a(n);
       ll ts=0;
       bool saw1=true,notIdx=false;
       for(int i=0;i<n;i++)
       {
            cin>>a[i];
            ts+=a[i];
            if(a[i]>1)
            saw1=false;
            if(i>0 && i<n-1 && a[i]>=2)
            notIdx=true;
       }
       if(saw1)
       cout<<-1<<endl;
       else if(notIdx)
       cout<<ts-1<<endl;
       else
       cout<<ts-n+1<<endl;
    }
    return 0;
}