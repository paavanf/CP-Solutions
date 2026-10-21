#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--)
{
    int n,s;
    cin>>n>>s;
    int qna=-1;
    for(int i=0;i<=n;i++)
    {
        int incorrect=4*i-s;
        if(incorrect>=0 && i+incorrect<=n)
        {
            qna=i+incorrect;
            break;
        }
    }
    cout<<qna<<endl;
}
return 0;
}
