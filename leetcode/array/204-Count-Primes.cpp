using ll=long long;
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
        return 0;
        int ct=n/2;
        vector<bool>p(n,true);
        //p[0]=p[1]=0;
        for(ll i=3;i*i<n;i+=2)
        {
            if(p[i])
            {
                //ct++;
                for(ll j=i*i;j<n;j+=2*i)
                {
                    if(p[j])
                    {
                        p[j]=false;
                        ct--;
                    }
                }
            }
        }
        /*for(int i=2;i<n;i++)
        {
            if(p[i])
            ct++;
        }*/
        return ct;
    }
};