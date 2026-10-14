class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        if(sum>9*num)
            return "";
        int a=sum;
        for(int i=0;i<num;i++)
            {
                int d=min(9,a);
                ans.push_back('0'+d);
                a-=d;
            }
        if(a!=0)
            return "";
        return ans;
    }
};