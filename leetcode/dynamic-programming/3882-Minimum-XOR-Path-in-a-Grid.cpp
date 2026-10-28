class Solution {
    int ans = 1e9;

    void solve(int i, int j, int xr, vector<vector<int>>& grid, vector<vector<vector<bool>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        xr ^= grid[i][j];

        if (i == m - 1 && j == n - 1) {
            ans = min(ans, xr);
            return;
        }

        if (dp[i][j][xr])
            return;

        dp[i][j][xr] = true;

        if (i + 1 < m)
            solve(i + 1, j, xr, grid, dp);

        if (j + 1 < n)
            solve(i, j + 1, xr, grid, dp);

        return;
    }

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(1024, false)));

        ans = 1e9;
        solve(0, 0, 0, grid, dp);

        return ans;
    }
};