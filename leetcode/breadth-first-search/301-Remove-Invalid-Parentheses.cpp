class Solution {
public:
    /*bool valid(string s)
    {
        int ct=0;
        for(char c:s)
        {
            if(c=='(')
            ct++;
            else if(c==')')
            ct--;
            if(ct<0)
            return false;
        }
        return ct==0;
    }*/
    void f(string &s,int idx,int l,int r,string &temp,int open,set<string>&ans)
    {
        int n=s.length();
        if(idx==n)
        {
            if(l==0 && r==0 && open==0)
            {
                //if(valid(temp))
                ans.insert(temp);
            }
            return;
        }
        char c=s[idx];
        if(c=='(' && l>0)
        f(s,idx+1,l-1,r,temp,open,ans);
        if(c==')'  && r>0)
        f(s,idx+1,l,r-1,temp,open,ans);
        //f(s,idx+1,l,r,temp+c,ans);
        if(c=='(')
        {
            temp.push_back(c);
            f(s,idx+1,l,r,temp,open+1,ans);
            temp.pop_back();
        }
        else if(c==')')
        {
            if(open>0)
            {
                temp.push_back(c);
                f(s,idx+1,l,r,temp,open-1,ans);
                temp.pop_back();
            }
        }
        else
        {
                temp.push_back(c);
                f(s,idx+1,l,r,temp,open,ans);
                temp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int l=0,r=0;
        //find minimum number of '(' and ')' to remove
        for(char c:s)
        {
            if(c=='(')
            l++;
            else if(c==')')
            {
                if(l>0)
                l--;
                else
                r++;
            }
        }
        set<string>ans;
        string temp="";
        f(s,0,l,r,temp,0,ans);
        return vector<string>(ans.begin(),ans.end());
    }
};