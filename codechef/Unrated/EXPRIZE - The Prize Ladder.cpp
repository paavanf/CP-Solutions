#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
	// your code goes here
int t;
cin>>t;
while(t--)
{
    ll n;
    cin>>n;
    ll l=1,h=2000000;
    ll lk=1;
    while(l<=h)
    {
        ll mid=l+(h-l)/2;
        ll K=mid+(mid-1)*mid*(mid+1)/6;
        if(K<=n)
        {
            lk=mid;
            l=mid+1;
        }
        else
        h=mid-1;
    }
    cout<<lk<<endl;
}
return 0;
}
