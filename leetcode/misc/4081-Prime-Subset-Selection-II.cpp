class Solution {
public:
    int solve(int i, int rem, vector<int>& primes,
              vector<vector<int>>& dp) {
        if (rem == 0)
            return 0;

        if (i == primes.size())
            return 1000000;

        if (dp[i][rem] != -1)
            return dp[i][rem];

        int notTake = solve(i + 1, rem, primes, dp);
        int take = 1000000;

        if (primes[i] <= rem) {
            int res = solve(i + 1, rem - primes[i], primes, dp);
            if (res != 1000000)
                take = 1 + res;
        }

        return dp[i][rem] = min(take, notTake);
    }

    vector<int> maxPrimeSubset(int n, int s) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;

        if (n >= 1)
            isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        vector<int> primes;

        for (int i = 2; i <= min(n, s); i++) {
            if (isPrime[i])
                primes.push_back(i);
        }

        int m = primes.size();

        vector<vector<int>> dp(
            m + 1, vector<int>(s + 1, -1)
        );

        // Find the largest achievable sum.
        int target = s;

        while (target > 0) {
            if (solve(0, target, primes, dp) != 1000000)
                break;
            target--;
        }

        if (target == 0)
            return {};

        // Minimum number of primes for the optimal sum.
        int need = solve(0, target, primes, dp);

        // Reconstruct lexicographically smallest answer.
        vector<int> ans;
        int i = 0;

        while (i < m && target > 0) {
            if (primes[i] <= target &&
                solve(i + 1, target - primes[i], primes, dp) == need - 1) {
                ans.push_back(primes[i]);
                target -= primes[i];
                need--;
            }

            i++;
        }

        return ans;
    }
};