#include <bits/stdc++.h>
using ll=long long;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        ll fixed_sum=(x-1)+(y+1);
        ll target_val=0;
        //formula
        //a+b=(a xor b)+ 2*(a & b)
        //to maximize the xor part we need to make (a&b)~0
        //0 will happen when no same posi in the binary representations does not have the set bit
        for(int i=30;i>=0;i--)
        {
            if((fixed_sum>>i)&1)
            {
                if(target_val+(1LL<<i)<=x)//because x is always decreasing
                {
                    target_val+=(1LL<<i);
                }
            }
        }
        ll ops=x-target_val;
        cout<<fixed_sum<<" "<<ops<<endl;
    }
    return 0;
}