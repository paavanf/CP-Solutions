class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        // unordered_map<int, vector<int>> log;
        // for(auto it : logs) 
        //     log[it[0]].push_back(it[1]);

        // for(auto& [id, v] : log)
        //     sort(v.begin(), v.end());
        
        // for(auto [id, v] : log) {
        //     cout << id << " : ";
        //     for(auto it : v) cout << it << " ";
        //     cout << endl;
        // }

        // vector<int> ans(queries.size());

        // vector<pair<int, int>> q;
        // for(int i=0; i<queries.size(); i++) v.push_back({qeires[i], i});
        // sort(v.begin(), v.end());

        // int left = 0, right = 0;
        // int count = 0;
        // for(auto [t, i] : v) {
        //     while(right < logs.size() && logs[r][1] <= t) {
        //         if(logs[right][0])
        //     }
        //     ans[i] = count;
        // }

        // return ans;

        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int m = queries.size();
        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) q.emplace_back(queries[i], i);
        sort(q.begin(), q.end());
        vector<int> ans(m);
        unordered_map<int, int> freq;
        int active = 0;
        int left = 0, right = 0;
        int L = logs.size();
        for (auto& [time, idx] : q) {
            while (right < L && logs[right][1] <= time) {
                int s = logs[right][0];
                if (++freq[s] == 1) active++;
                right++;
            }
            while (left < right && logs[left][1] < time - x) {
                int s = logs[left][0];
                if (--freq[s] == 0) active--;
                left++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};