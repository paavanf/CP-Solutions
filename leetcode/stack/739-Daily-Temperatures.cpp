class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && t[st.top()]<=t[i])
            st.pop();
            if(!st.empty())
            ans[i]=st.top()-i;
            else
            ans[i]=0;
            st.push(i);
        }
        return ans;
    }
};