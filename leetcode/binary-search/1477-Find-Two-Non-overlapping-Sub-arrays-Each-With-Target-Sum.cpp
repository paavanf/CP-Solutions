class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>best(n,INT_MAX);//remembers the shortest valid subarray we have found so far.
        int sm=0,s=0,curr=INT_MAX,ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sm+=arr[i];
            while(sm>target)
            {
                sm-=arr[s];
                s++;
            }
            if(sm==target)
            {
                int len=i-s+1;
                //previous subarray
                if(s>0 && best[s-1]!=INT_MAX)
                {
                    ans=min(ans,best[s-1]+len);//direct adding because we need the sum
                }
                curr=min(curr,len);
            }
            best[i]=curr;
        }
        return ans==INT_MAX?-1:ans;
    }
};