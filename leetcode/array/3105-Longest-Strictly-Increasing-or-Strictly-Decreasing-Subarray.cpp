class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int cLength = 0, maxLength = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                cLength++;
            } else {
                maxLength = max(maxLength, cLength);
                cLength = 0;
            }
        }
        maxLength = max(maxLength, cLength);

        cLength = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                cLength++;
            } else {
                maxLength = max(maxLength, cLength);
                cLength = 0;
            }
        }

        maxLength = max(maxLength, cLength);
        return maxLength+1;
    }
};