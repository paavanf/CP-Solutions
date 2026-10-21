#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
	// your code goes here
int t;
cin>>t;
while(t--)
{
    //int n,d;
    ll n;
    int d;
    cin>>n>>d;
    if(n==0 && d==0)
    {
        cout<<n<<endl;
        continue;
    }
    ll placeValue=1;
    while(n/placeValue>0)
    {
        /*int x=n;
        bool flag=false;
        int temp=x;
        while(temp>0)
        {
            if(temp%10==d)
            {
                flag=true;
                break;
            }
            temp/=10;
        }
        //special case
        if(n==0 && d==0)
        flag=true;
        
        string num=to_string(n);
        bool flag=false;
        int sz=num.size();
        for(int i=0;i<sz;i++)
        {
            if(num[i]-'0'==d)
            {
                num[i]='0'+d+1;
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            cout<<n<<endl;
            break;
        }
        n++;
        */
        if((n/placeValue)%10==d)
        {
            n+=placeValue-(n%placeValue);
            placeValue=1;
        }
        else
        placeValue*=10;
    }
    cout<<n<<endl;
}
return 0;
}
