class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int result = 1, n = position.size(), lastSpeed = speed[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (position[i + 1] - position[i] <= distance || speed[i] > lastSpeed) {
                continue;
            } else {
                result++, lastSpeed = speed[i];
            }
        }

        return result;
    }
};