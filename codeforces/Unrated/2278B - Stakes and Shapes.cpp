#include <bits/stdc++.h>
using ll=long long;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int tr=x+y+z;
        if(x>=y && x>=z)
        cout<<string(tr,'P')<<endl;
        else if(y>=x && y>=z)
        cout<<string(tr,'R')<<endl;
        else
        cout<<string(tr,'S')<<endl;
    }
    return 0;
}