class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        int maxP = INT_MIN;
        vector<int> ans = {-1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = arr[i].first;
                int b = arr[j].first;

                if (a + b == target && a != b) {
                    int p = a * b;

                    if (p > maxP) {
                        maxP = p;
                        ans = {arr[j].second, arr[i].second};
                    }
                }
            }
        }

        return ans;
    }
};