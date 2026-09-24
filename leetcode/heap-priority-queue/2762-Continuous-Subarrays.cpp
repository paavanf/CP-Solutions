using ll=long long;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        multiset<int>st;
        int j=0;
        ll ct=0;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
            //max(win)-min(win)
            while(*st.rbegin()-*st.begin()>2)
            {
                st.erase(st.find(nums[j]));
                j++;
            }
            ct+=i-j+1;
        }
        return ct;
    }
};