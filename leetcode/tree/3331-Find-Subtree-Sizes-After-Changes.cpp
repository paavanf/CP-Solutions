
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> subtreeSize;
    vector<int> last;

    void dfs(int node, vector<int>& parent, string& s) {

        int ch = s[node] - 'a';

        // Store the previous node having the same character
        int prev = last[ch];

        // Find the closest ancestor with the same character
        int target = (prev != -1) ? prev : parent[node];

        // Update last occurrence of this character
        last[ch] = node;

        // Initially, every node has subtree size 1
        subtreeSize[node] = 1;

        // Traverse all children
        for (auto child : adj[node]) {
            dfs(child, parent, s);
        }

        // Add current subtree size to its target parent
        if (node != 0) {
            subtreeSize[target] += subtreeSize[node];
        }

        // Backtrack: restore previous occurrence
        last[ch] = prev;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        adj.resize(n);
        subtreeSize.assign(n, 1);
        last.assign(26, -1);

        // Build adjacency list
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Start DFS from root
        dfs(0, parent, s);

        return subtreeSize;
    }
};
