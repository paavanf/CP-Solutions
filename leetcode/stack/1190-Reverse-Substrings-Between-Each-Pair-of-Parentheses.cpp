class Solution {
public:
    string reverseParentheses(string s) {
        string ans,temp;
        for(char c:s)
        {
            if(c!=')')
            ans+=c;
            else
            {
                temp="";
                while(ans.back()!='(')
                {
                    temp+=ans.back();
                    ans.pop_back();
                }
                ans.pop_back();
                ans+=temp;
            }
        }
        return ans;
    }
};