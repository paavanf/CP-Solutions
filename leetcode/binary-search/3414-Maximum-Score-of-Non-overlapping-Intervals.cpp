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
        vector<int>prev(n);//Yeh array store karega ki current i interval se pehle kaunsa latest interval aa sakta hai jo iske saath overlap na kare.
        for(int i=0;i<n;i++)
        {
            int l=0,h=i-1,ans=-1;
            while(l<=h)
            {
            int mid=l+(h-l)/2;
            if(score[mid][1]<score[i][0])
            {
                ans=mid;
                l=mid+1;//Par hume sabse latest (sabse right side wala) candidate chahiye jo time ke sabse kareeb ho. Isliye hum search space ko right mein shift kar dete hain
            }
            else
            h=mid-1;
            }
            prev[i]=ans;
        }
        //Yahan hume tie-breaker handle karna hai, isliye hum ek pair store kar rahe hain: {max_score, vector_of_indices that produce that score}.
        vector<vector<pair<ll,vector<int>>>>dp(n+1,vector<pair<ll,vector<int>>>(5,{0LL,{}}));
        //dp[i][j] =maximum score using first i intervals and choosing at most j intervals
        //meaning Considering the first "i" intervals, what is the maximum score I can get by selecting at most "j" non-overlapping intervals?
        for(int i=1;i<=n;i++)//no of intervals considered
        {
            //score array 0-based hai, par dp table 1-based hai. Isliye score array access karte waqt i - 1 use hoga.
            for(int j=1;j<=4;j++)
            {
                //Choice1:-Current interval ko reject kar do. Iska answer wahi hoga jo isse pehle tak ke best i-1 intervals mein j capacity ke saath tha.
                auto leave=dp[i-1][j];
                //Choice2:-Current interval ko select kar lo. Iske liye hume pichle valid state par jana hoga (p + 1 kyunki DP 1-based hai) aur capacity ek kam ho jayegi (j - 1).
                int p=prev[i-1];//Current interval ke liye pichla non-overlapping valid index nikala.
                auto take=dp[p+1][j-1];
                //Current state ka total score update kiya (Previous best score + current weight).
                take.first+=score[i-1][2];
                //Current interval ka original index answer array mein daal diya.
                take.second.push_back(score[i-1][3]);
                sort(take.second.begin(),take.second.end()); //Keep indices sorted for lexicographical comparison
                // Tie-breaker logic
                if (take.first>leave.first)
                {
                    dp[i][j]=take;
                }
                else if(take.first==leave.first)
                {
                    // C++ vector < operator naturally compares lexicographically
                    dp[i][j]=(take.second<leave.second)?take:leave;
                }
                else
                {
                    dp[i][j]=leave;
                }
            }
        }
        // The answer is the vector stored in the final DP state
        return dp[n][4].second;
    }
};