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
        string s;
        cin>>s;
        if(s[0]=='1')
        {
            int ops=0;
            for(char c:s)
            {
                if(c=='0')
                ops++;
            }
            cout<<ops<<endl;
        }
        else
        {
            int ops=0,ct1=0;
            for(char c:s)
            {
                if(c=='1')
                ct1++;
                else
                ops=min(ops+1,ct1);
            }
        cout<<ops<<endl;
        }
    }
    return 0;
}