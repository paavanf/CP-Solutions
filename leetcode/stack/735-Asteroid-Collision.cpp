class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int a:asteroids)
        {
            bool flag=true;
            while(flag && a<0 && !st.empty() && st.top()>0)
            {
                if(st.top()<-a)
                st.pop();
                else if(st.top()==-a)
                {
                    st.pop();
                    flag=false;
                }
                else
                flag=false;
            }
            if(flag)
            st.push(a);
        }
        vector<int>ans(st.size());
        for(int i=st.size()-1;i>=0;i--)
        {
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};