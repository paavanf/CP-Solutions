class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        map<char, pair<int, int>> charToDirectionMap = {{'U', {-1, 0}}, {'D', {+1, 0}}, {'L', {0, -1}}, {'R', {0, +1}}};
        for (string &s : commands) {
            char c = s[0];
            pair<int, int> direction = charToDirectionMap[c];
            i += direction.first, j += direction.second;
        }
        return i * n + j;
    }
};