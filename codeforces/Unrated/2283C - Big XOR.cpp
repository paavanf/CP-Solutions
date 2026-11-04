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
       //get the xor sum
       int xs=0;
       for(int i=1;i<=n;i++)
       xs^=i;
       int hb=0;
       
       while((1<<(hb+1))<=n)
       hb++;
       vector<int>arr(n+1,0);
       int mask=1<<(hb+1);
       int reqTarget=(2*(mask-1))^xs;
       for(int i=28;i>=0;i--)
       {
        int x=1<<i;
        if(x>n)
        continue;
        int req=reqTarget>>(i+1);
        if(req&1)
        {
            arr[x]=1;
            reqTarget^=x;
            reqTarget^=x*2;
        }
       }
       for(int i=1;i<=n;i++)
       cout<<arr[i]<<" ";
       cout<<"\n";
    }
    return 0;
}