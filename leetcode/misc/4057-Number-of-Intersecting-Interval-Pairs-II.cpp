using ll=long long;
class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<ll>s(n),e(n);
        for(int i=0;i<n;i++)
        {
        s[i]=intervals[i][0];
        e[i]=intervals[i][1];
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int i=0,j=0;
        ll intersect=0;
        while(i<n)
        {
            while(j<n && e[j]<s[i])
            j++;
            intersect+=i-j;
            i++;
        }
        return intersect;
    }
};