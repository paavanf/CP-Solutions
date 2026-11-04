
class Solution {
public:
    using ll = long long;

    ll dfs(int i, int k, int x, int n,
           vector<ll>& cost, vector<vector<ll>>& dp) {

        // Successfully selected k subarrays
        if(k == 0)
            return 0;

        // Not enough elements remaining
        if(i + 1LL * k * x > n)
            return 1e18;

        if(dp[i][k] != -1)
            return dp[i][k];

        // Choice 1: Skip current index
        ll notTake = dfs(i + 1, k, x, n, cost, dp);

        // Choice 2: Take subarray starting at i
        ll take = cost[i] +
                  dfs(i + x, k - 1, x, n, cost, dp);

        return dp[i][k] = min(take, notTake);
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        ll sumLow = 0, sumHigh = 0;

        vector<ll> cost;

        // Calculate cost of every window of size x
        for(int i = 0; i < n; i++) {

            // Insert current element
            if(low.empty() || nums[i] <= *low.rbegin()) {
                low.insert(nums[i]);
                sumLow += nums[i];
            }
            else {
                high.insert(nums[i]);
                sumHigh += nums[i];
            }

            // Remove outgoing element
            if(i >= x) {
                int val = nums[i - x];

                auto it = low.find(val);

                if(it != low.end()) {
                    low.erase(it);
                    sumLow -= val;
                }
                else {
                    it = high.find(val);
                    high.erase(it);
                    sumHigh -= val;
                }
            }

            // Rebalance multisets
            if(low.size() < high.size()) {
                int val = *high.begin();

                high.erase(high.begin());
                low.insert(val);

                sumHigh -= val;
                sumLow += val;
            }
            else if(low.size() > high.size() + 1) {
                int val = *low.rbegin();

                low.erase(prev(low.end()));
                high.insert(val);

                sumLow -= val;
                sumHigh += val;
            }

            // Calculate minimum operations for current window
            if(i >= x - 1) {
                ll median = *low.rbegin();

                ll currCost =
                    median * low.size() - sumLow +
                    sumHigh - median * high.size();

                cost.push_back(currCost);
            }
        }

        // Memoization table
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1));

        return dfs(0, k, x, n, cost, dp);
    }
};
