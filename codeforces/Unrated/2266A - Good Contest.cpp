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
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        cout<<n-min({a1,a2,a3})<<endl;
    }
    return 0;
}