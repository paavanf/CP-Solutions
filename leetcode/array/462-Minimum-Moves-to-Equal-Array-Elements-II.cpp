class Solution {
public:
    int minMoves2(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int mean = nums[nums.size() / 2];
        int moves = 0;
        for (int i : nums) {
            moves += abs(mean - i);
        }
        return moves;
    }
};