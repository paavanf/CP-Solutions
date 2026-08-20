class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //among all the preoj that we can currently afford,always choose the one with the maximum profit
        //need 2 heaps one for the required capital and one for maximum profits
        //minHeap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;
        //maxHeap
        priority_queue<int>pq2;
        int n=profits.size();
        for(int i=0;i<n;i++)
        pq1.push({capital[i],profits[i]});
        while(k--)
        {
            while(!pq1.empty() && pq1.top().first<=w)
            {
                pq2.push(pq1.top().second);
                pq1.pop();
            }
            if(pq2.empty())
            break;
            w+=pq2.top();
            pq2.pop();
        }
        return w;
    }
};