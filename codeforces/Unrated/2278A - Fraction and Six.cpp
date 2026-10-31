#include <bits/stdc++.h>
using ll=long long;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string p,q;
        cin>>p>>q;
        q+="six";
        sort(p.begin(),p.end());
        sort(q.begin(),q.end());
        if(p==q)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}