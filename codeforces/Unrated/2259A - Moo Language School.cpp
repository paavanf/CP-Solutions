#include <bits/stdc++.h>
using ll=long long;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int school=0;
        for(int i=0;i<n;i+=k)
        {
            bool build=true;
            for(int j=i;j<i+k;j++)
            {
                if(s[j]=='0')
                {
                    build=false;
                    break;
                }
            }
            if(build)
            school++;
        }
        cout<<school<<endl;
    }
    return 0;
}