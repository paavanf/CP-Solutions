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
        for(int i=0;i<n;i++)
        cin>>a[i];
        int l=-1,r=-1;
        //decide the boundaries
        for(int i=0;i<n;i++)
        {
            if(a[i]==1 || a[i]==-1)
            {
                if(l==-1)
                {
                    l=i;
                }
                r=i;
            }
        }
        //confirming the boundaries
        if(l!=-1)
        a[l]=1;
        if(r!=-1)
        a[r]=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==-1)
            a[i]=0;
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}