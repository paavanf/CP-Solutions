class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<pair<int, int>> st;
        for(int i=0; i<m; i++) {
            unordered_map<int, int> row;
            for(int j=0; j<n; j++) {
                row[i] += grid[i][j];
            }
            if(row[i] > 1) {
                for(int j=0; j<n; j++) {
                    if(grid[i][j]) st.insert({i, j});
                }
            }
        }
        for(int j=0; j<n; j++) {
            unordered_map<int, int> col;
            for(int i=0; i<m; i++) {
                col[j] += grid[i][j];
            }
            if(col[j] > 1) {
                for(int i=0; i<m; i++) {
                    if(grid[i][j]) st.insert({i, j});
                }
            }
        }

        return st.size();
    }
};