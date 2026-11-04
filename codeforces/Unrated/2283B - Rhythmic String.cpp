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
       sort(a.begin(),a.end());
       int maxi_ele=INT_MIN;
       for(int i=0;i<n;i++)
       {
        if(i>0 && a[i]==a[i-1])
        continue;
        int ele=0;
        for(int j=i;j<n;j++)
        {
            if(a[j]%a[i]==0)
            ele++;
        }
        maxi_ele=max(maxi_ele,ele);
       }
       cout<<n-maxi_ele<<endl;
    }
    return 0;
}