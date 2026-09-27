class Solution {
public:
    bool check(vector<int>&fq)
    {
        for(int i=1;i<=500;i++)
        {
            if(fq[i]==0)
            continue;
            for(int j=i;i+j<=500;j++)
            {
                if(fq[j]==0)
                continue;
                int k=i+j;
                if(fq[k]==0)
                continue;
                if(i==j)
                {
                    if(fq[i]>=2)
                    return false;
                }
                else
                return false;
            }
        }
        return true;
    }
    int maxSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,maxiLen=0;
        vector<int>fq(501,0);
        for(int r=0;r<n;r++)
        {
            fq[nums[r]]++;
            while(!check(fq))
            {
                fq[nums[l]]--;
                l++;
            }
            maxiLen=max(maxiLen,r-l+1);
        }
        return maxiLen;
    }
};