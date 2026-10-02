class Solution {
public:
    void f(int op,int cp,int n,string s,vector<string>&ans)
    {
        if(op==n && cp==n)
        {
            ans.push_back(s);
            return;
        }
        if(op<n)
        f(op+1,cp,n,s+'(',ans);
        if(cp<op)
        f(op,cp+1,n,s+')',ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        f(0,0,n,"",ans);
        return ans;
    }
};