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
        {
            //height-idx will remain constant
            int val;
            cin>>val;
            a[i]=val-(i+1);
        }
        //sort and remove duplicates
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        int sz=a.size();
        int incCurrLen=1,maxiLen=1;
        for(int i=1;i<sz;i++)
        {
            if(a[i]==a[i-1]+1)
            incCurrLen++;
            else
            incCurrLen=1;
            maxiLen=max(maxiLen,incCurrLen);
        }
        cout<<maxiLen<<endl;
    }
    return 0;
}