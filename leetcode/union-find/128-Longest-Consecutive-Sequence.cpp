class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int n:nums)
        st.insert(n);
        int ans=0;
        for(int n:st)
        {
            if(st.find(n-1)==st.end())
            {
                //means not found so n is starting point
                int sn=n;
                int currLen=1;
                while(st.find(sn+1)!=st.end())
                {
                    //means it is available
                    sn++;
                    currLen++;
                }
                ans=max(ans,currLen);
            }
        }
        return ans;
    }
};