class Solution {
public:
int EAC(int i,int j,string &s)
    {
        int l=i;
        int r=j;
        int ct=0;
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            ct++;
            l--;
            r++;
        }
        return ct;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=EAC(i,i,s);
            ans+=EAC(i,i+1,s);
        }
        return ans;
    }
};