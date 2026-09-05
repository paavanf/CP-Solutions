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
        //pattern based for even numbers and odd numbers
        cin>>n;
        int odd=0;
        int even1=0,even2=0;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            if(val%2!=0)
            odd++;
            else if(val%4==2)
            even1++;
            else
            even2++;
        }
        cout<<max({odd,even1,even2})<<endl;
    }
    return 0;
}