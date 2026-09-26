class Solution {
public:
    int climbStairs(int n) {
        int sp1=1,sp2=1;
        for(int i=0;i<n-1;i++)
        {
            int temp=sp1;
            sp1=sp1+sp2;
            sp2=temp;
        }
        return sp1;
    }
};