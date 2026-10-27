class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>mtx(m,string(n,'#'));
        for(int i=0;i<n;i++)
            mtx[0][i]='.';
        for(int i=0;i<m;i++)
            mtx[i][n-1]='.';
        return mtx;
    }
};