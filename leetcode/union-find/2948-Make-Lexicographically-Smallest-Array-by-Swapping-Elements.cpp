class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)
        v[i]={nums[i],i};
        sort(v.begin(),v.end());
        //connected components
        priority_queue<int,vector<int>,greater<int>>pq;
        int l=0;
        while(l<n)
        {
            int r=l;
            //find the connected component
            while(r+1<n && v[r+1].first-v[r].first<=limit)
            r++;
            for(int i=l;i<=r;i++)
            pq.push(v[i].second);
            for(int i=l;i<=r;i++)
            {
                nums[pq.top()]=v[i].first;
                pq.pop();
            }
            l=r+1;
        }
        return nums;
    }
};