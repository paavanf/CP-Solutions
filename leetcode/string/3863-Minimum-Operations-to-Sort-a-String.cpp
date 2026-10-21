class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string temp = s;
        sort(temp.begin(), temp.end());
        if (s == temp)
            return 0;
        int i = 0;
        int j = n - 1;
        if (n == 2)
            return -1;
        while (i < n) {
            if (s[i] == temp[i])
                i++;
            else {
                break;
            }
        }
        while (j >= 0) {
            if (s[j] == temp[j])
                j--;
            else {
                break;
            }
        }

        if ((j - i + 1) < n)
            return 1;

        bool flag = false, flag2 = false;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == temp[0]) {
                flag = true;
                break;
            }
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == temp[n - 1]) {
                flag2 = true;
                break;
            }
        }
        if (flag || flag2)
            return 2;
        return 3;
    }
};