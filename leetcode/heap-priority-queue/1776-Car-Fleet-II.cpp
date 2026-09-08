class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n=cars.size();
        vector<double>ans(n,-1);
        stack<int>st;
        //traverse backwards
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty())
            {
                int j=st.top();
                //curr car cannot reach
                if(cars[i][1]<=cars[j][1])
                {
                    st.pop();
                    continue;
                }
                double t=(double)(cars[j][0]-cars[i][0])/abs(cars[j][1]-cars[i][1]);
                if(ans[j]==-1 || t<=ans[j])
                {
                    ans[i]=t;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};