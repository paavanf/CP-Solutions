using ll=long long;
class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a=0,b=1;
        while(true)
        {
            int s=a+b;
            ll ts=s+a+b;
            if(ts>n)
            return false;
            else if(ts==n)
            return true;
            a=b;
            b=s;
        }
        return false;
    }
};