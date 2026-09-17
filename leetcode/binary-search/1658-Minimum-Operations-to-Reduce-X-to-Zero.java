class Solution {
    public int minOperations(int[] nums, int x) {
        int n = nums.length;

        // C++: accumulate(nums.begin(), nums.end(), 0)
        int total = 0;
        for (int num : nums) {
            total += num;
        }

        int k = total - x;

        if (k < 0)
            return -1;

        if (k == 0)
            return n;

        int maxi = 0;

        // C++: unordered_map<int, int>
        HashMap<Integer, Integer> mpp = new HashMap<>();

        // prefix sum 0 occurs before index 0
        mpp.put(0, -1);

        int prefix = 0;

        for (int i = 0; i < n; i++) {

            prefix += nums[i];

            // Check if prefix - k exists
            if (mpp.containsKey(prefix - k)) {
                maxi = Math.max(maxi, i - mpp.get(prefix - k));
            }

            // Store only the first occurrence
            if (!mpp.containsKey(prefix)) {
                mpp.put(prefix, i);
            }
        }

        return maxi == 0 ? -1 : n - maxi;
    }
}