using ll=long long;
const ll maxi=2e15;
ll fact(int n)
{
    if(n<0)
    return 0;
    ll p=1;
    for(int i=1;i<=n;i++)
    {
        if(p>maxi/i)
        return maxi;
        p*=i;
    }
    return p;
}
ll ctWays(int o,int e,int next)//After choosing the current number, how many valid permutations can I make with the remaining odd and even numbers
{
    //nxt=1;means next number must be odd
    //nxt=0;means next number must be 
    if(o<0 || e<0)
    return 0;
    if(next==1)
    {
        if(o!=e && o!=e+1)
        return 0;
    }
    else
    {
        if(e!=o && e!=o+1)
        return 0;
    }
    ll fo=fact(o);
    ll fe=fact(e);
    if(fo>maxi/fe)
    return maxi;
    return fo*fe;
}
class Solution {
public:
    vector<int> permute(int n, long long k) {
        int o=(n+1)/2;
        int e=n/2;
        // Count total valid permutations
        ll total=0;
        // Start with odd
        total+=ctWays(o,e,0);
        // Start with even
        total+=ctWays(o,e,1);
        if(k>total)
        return {};
        vector<int>ans;
        vector<bool>used(n+1,false);
        int prev=-1;
        while(ans.size()<n)
        {
            for(int i=1;i<=n;i++)
            {
                if(used[i])
                continue;
                if(prev!=-1 && i%2==prev)
                continue;
                int no=o,ne=e;
                if(i%2==1)
                no--;
                else
                ne--;
                int next=1-(i%2);
                ll ways;
                if(ans.size()+1==n)
                ways=1;
                else
                ways=ctWays(no,ne,next);
                if(ways==0)
                continue;
                if(k>ways)
                k-=ways;
                else
                {
                    ans.push_back(i);
                    used[i]=true;
                    o=no;
                    e=ne;
                    prev=i%2;
                    break;
                }
            }
        }
        return ans;
    }
};