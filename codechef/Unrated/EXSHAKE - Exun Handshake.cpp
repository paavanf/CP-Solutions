#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--)
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a.begin(),a.end());
    int ppl=0,maxiGrps=0;
    for(int i=0;i<n;i++)
    {
        int addPpl=ppl+a[i];
        if(addPpl*(addPpl-1)/2<=m)
        {
            ppl=addPpl;
            maxiGrps++;
        }
        else
        break;
    }
    cout<<maxiGrps<<endl;
}
return 0;
}
