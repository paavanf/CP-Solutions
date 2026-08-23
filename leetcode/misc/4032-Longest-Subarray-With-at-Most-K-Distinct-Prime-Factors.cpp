class Solution {
public:
 //we will use set because we care about distinct prime factors
    set<int>pfs(int n)
    {
        set<int>st;
        for(int i=2;i*i<=n;i++)
            {
                if(n%i==0)
                {
                    st.insert(i);
                    while(n%i==0)
                        n/=i;
                }
            }
        if(n>1)
            st.insert(n);
        return st;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int distinct=0;
        unordered_map<int,int>fq;
        int l=0,sz=0;
        for(int r=0;r<n;r++)
        {
           set<int>pf=pfs(nums[r]);
           for(int f:pf)
           {
            if(fq[f]==0)
            distinct++;
            fq[f]++;
           }
           while(distinct>k)
           {
            set<int>rf=pfs(nums[l]);
            for(int f:rf)
            {
                fq[f]--;
                if(fq[f]==0)
                distinct--;
            }
            l++;
           }
           sz=max(sz,r-l+1);
        }
        return sz;
    }
};