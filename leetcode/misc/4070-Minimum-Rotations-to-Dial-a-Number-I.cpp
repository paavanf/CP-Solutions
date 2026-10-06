class Solution {
public:
    int d(char a,char b)
    {
        int x=abs((a-'0')-(b-'0'));
        return min(x,10-x);
    }
    int minRotations(string s) {
        int tot=0;
        char last='0';
        for(char c:s)
        {
            tot+=d(last,c);
            last=c;
        }
        return tot;
    }
};