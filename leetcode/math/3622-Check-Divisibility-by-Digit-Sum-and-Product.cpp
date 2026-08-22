class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n,s=0,p=1;
        while(temp>0)
        {
            int d=temp%10;
            s+=d;
            p*=d;
            temp/=10;
        }
        int sm=p+s;
        return (n%sm==0);
    }
};