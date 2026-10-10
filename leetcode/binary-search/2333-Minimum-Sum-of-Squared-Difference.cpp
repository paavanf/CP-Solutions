class Solution {
public:
    using ll = long long;

    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        ll sum = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            maxi = max(maxi, diff[i]);
        }

        ll k = (ll)k1 + k2;

        if (sum <= k) return 0;

        int low = 0, high = maxi;

        while (low < high) {
            int mid = low + (high - low) / 2;
            ll need = 0;

            for (int d : diff) {
                if (d > mid) {
                    need += d - mid;
                }
            }

            if (need <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int level = low;

        for (int i = 0; i < n; i++) {
            k -= max(0, diff[i] - level);
            diff[i] = min(diff[i], level);
        }

        for (int i = 0; i < n && k > 0; i++) {
            if (diff[i] == level) {
                diff[i]--;
                k--;
            }
        }

        ll ans = 0;

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};