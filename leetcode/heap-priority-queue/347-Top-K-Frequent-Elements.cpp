class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>fq;
        //store freq
        for(int n:nums)
        fq[n]++;
        //min heap{fq,no};
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto &it:fq)
        {
            int num=it.first;
            int ct=it.second;
            pq.push({ct,num});
            if(pq.size()>k)
            pq.pop();
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};