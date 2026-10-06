class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, insertions = 0;
    for (char c : s) {
        if (c == '(') {
            open++;
        } else { // c == ')'
            if (open > 0) {
                open--; // match with an open '('
            } else {
                insertions++; // need to insert '(' before this ')'
            }
        }
    }
    return insertions + open; // unmatched '(' need closing ')'
    }
};