#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void merge(int l,int mid,int r,vector<pair<int,int>>&p,vector<int>&arr)
{
    vector<pair<int,int>>temp;
    int i=l;
    int j=mid+1;
    while(i<=mid && j<=r)
    {
        if(p[i].first<p[j].first)
        {
            temp.push_back(p[i]);
            i++;
        }
        else
        {
            arr[p[j].second]+=(i-l);
            temp.push_back(p[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(p[i]);
        i++;
    }
    while(j<=r)
    {
        arr[p[j].second]+=(i-l);
        temp.push_back(p[j]);
        j++;
    }
    for(int x=l;x<=r;x++)
    p[x]=temp[x-l];
}
void mergeSort(int l,int r,vector<pair<int,int>>&p,vector<int>&arr)
{
    if(l>=r)
    return;
    int mid=l+(r-l)/2;
    mergeSort(l,mid,p,arr);
    mergeSort(mid+1,r,p,arr);
    merge(l,mid,r,p,arr);
}
int main() {
	// your code goes here
int t;
cin>>t;
while(t--)
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>p(n);
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>p[i].first;
        p[i].second=i;
    }
    mergeSort(0,n-1,p,arr);
    ll miniOps=0;
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        int ulta=arr[i];
        if(ulta>0)
        {
            if(k==1)
            {
                flag=false;
                break;
            }
            miniOps+=(ulta+k-2)/(k-1);
        }
    }
    if(!flag)
    cout<<-1<<endl;
    else
    cout<<miniOps<<endl;
}
return 0;
}
