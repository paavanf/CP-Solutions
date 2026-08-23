class Solution {
public:
    bool isPalindromic(string s) {
        string bs="";
        for(char c:s)
        {
        for(int i=7;i>=0;i--)
        {
            bs+=((c>>i)&1)+'0';
        }
        }
        string pal=bs;
        reverse(bs.begin(),bs.end());
        return bs==pal;
    }
};