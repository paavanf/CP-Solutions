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
        int ct0=0;
        for(int i=0;i<n;i++)
        {
        cin>>a[i];
        if(a[i]==0)
        ct0++;
        }
        if(ct0<2)
        cout<<-1<<endl;
        else{
            int ops=0;
            if(a[0]==1)
            ops++;
            if(a[n-1]==1)
            ops++;
            cout<<ops<<endl;
        }
    }
    return 0;
}