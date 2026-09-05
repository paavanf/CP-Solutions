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
        //case1
        if(ct0==0)
        {
            cout<<"YES"<<endl;
            string s(n,'A');
            cout<<s<<endl;
            continue;
        }
        //case2
        if(ct0==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        //special case so that we divide the multisets
        cout<<"YES"<<endl;
        //first get the fq of each ele
        vector<int>fq(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(a[i]<=n)
            fq[a[i]]++;
        }
        //get any 2 ms equal MEX
        int mex=0;
        while(mex<=n && fq[mex]>=2)
        mex++;
        string s(n,'A');
        vector<int>vis(mex,0);
        for(int i=0;i<n;i++)
        {
            if(a[i]<mex)
            {
                if(vis[a[i]]==0)
                s[i]='C';
                else if(vis[a[i]]==1)
                s[i]='B';
                else
                s[i]='C';
                vis[a[i]]++;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}