class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s=="")
        return false;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='{' || ch=='(' || ch=='[')
            {
                st.push(ch);
            }
            else
            {
                if(st.empty())
                return false;
                char c=st.top();
                if ((ch == ')' && c != '(') || (ch == '}' && c != '{') || (ch == ']' && c != '['))
                    return false;
                    st.pop();
            }
        }
        if(st.empty())
        return true;
        else 
        return false;
    }
};