class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        stack<string>st;
        string ans;
        for(int i=0;i<n;i++)
        {
            if(path[i]=='/')
            continue;
            string temp;
            while(i<n && path[i]!='/')
            {
                temp+=path[i];
                i++;
            }
            if(temp==".")
            continue;
            else if(temp=="..")
            {
                if(!st.empty())
                st.pop();
            }
            else
            st.push(temp);
        }
        vector<string>v;
        while(!st.empty())
        {
            v.push_back(st.top());
            //ans+="/"+st.top();
            st.pop();
        }
        int sz=v.size();
        for(int i=sz-1;i>=0;i--)
        ans+="/"+v[i];
        if(ans.size()==0)
        return "/";
        return ans;
    }
};