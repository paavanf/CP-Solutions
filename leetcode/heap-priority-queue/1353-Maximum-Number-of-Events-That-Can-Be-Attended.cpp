class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0,day=0,eventCt=0;
        while(i<n || !pq.empty())
        {
            //base case
            if(pq.empty())
            day=events[i][0];
            while(i<n && events[i][0]==day)
            {
                //pq is for endDay wise
                pq.push(events[i][1]);
                i++;
            }
            //remove the events which can no longer suffice
            while(!pq.empty() && pq.top()<day)
            pq.pop();
            //attend the event on the earliest day
            if(!pq.empty())
            {
                pq.pop();
                day++,eventCt++;
            }
        }
        return eventCt;
    }
};