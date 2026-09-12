using ll=long long;
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& inv) {
        //interval DP
        int n=inv.size();
        vector<vector<ll>>score(n,vector<ll>(4));//start,end,weight,original_index
        for(int i=0;i<n;i++)
        {
            score[i]={inv[i][0],inv[i][1],inv[i][2],i};
        }
        //sort by ending time
        sort(score.begin(),score.end(),[](auto &a,auto &b)
        {
            if(a[1]!=b[1])
            return a[1]<b[1];
            return a[3]<b[3];
        });
        vector<int>prev(n);//last interval which can come before i
        //bs for last non-overlapping interval
        for(int i=0;i<n;i++)
        {
            int l=0,h=i-1,ans=-1;
            while(l<=h)
            {
            int mid=l+(h-l)/2;
            if(score[mid][1]<score[i][0])
            {
                ans=mid;
                l=mid+1;
            }
            else
            h=mid-1;
            }
            prev[i]=ans;
        }
         /*
            dp[i][k] =
            maximum score using first i jobs
            and choosing at most k jobs.

            i = number of jobs considered
            k = number of jobs allowed
        */
        vector<vector<pair<ll, vector<int>>>> dp(n + 1, vector<pair<ll, vector<int>>>(5, {0LL, {}}));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 4; j++) {
                // Option 1: Don't take the current interval
                auto leave = dp[i - 1][j];
                
                // Option 2: Take the current interval
                int p = prev[i - 1];
                auto take = dp[p + 1][j - 1]; 
                
                take.first += score[i - 1][2];
                take.second.push_back(score[i - 1][3]);
                sort(take.second.begin(), take.second.end()); // Keep indices sorted for lexicographical comparison
                
                // Tie-breaker logic
                if (take.first > leave.first) {
                    dp[i][j] = take;
                } else if (take.first == leave.first) {
                    // C++ vector < operator naturally compares lexicographically
                    dp[i][j] = (take.second < leave.second) ? take : leave;
                } else {
                    dp[i][j] = leave;
                }
            }
        }
        // The answer is the vector stored in the final DP state
        return dp[n][4].second;
    }
};