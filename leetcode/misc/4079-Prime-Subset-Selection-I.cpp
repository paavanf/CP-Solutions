class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool>p(n+1,true);
        p[0]=p[1]=false;
        for(int i=2;i*i<=n;i++)
        {
            if(p[i])
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    p[j]=false;
                }
            }
        }
        vector<int>ans;
        int sm=0;
        for(int i=2;i<=n;i++)
        {
            if(p[i])
            {
                if(sm+i<=s)
                {
                    ans.push_back(i);
                    sm+=i;
                }
                else
                break;
            }
        }
        return ans;
    }
};