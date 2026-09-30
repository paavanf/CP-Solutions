class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        //divided into 2 grps of 0 and 1
        int n=seq.size();
        vector<int>ans(n);
        int depth=0;
        for(int i=0;i<n;i++)
        {
            if(seq[i]=='(')
            {
                depth++;
                ans[i]=depth%2;
            }
            else
            {
                ans[i]=depth%2;
                depth--;
            }
        }
        return ans;
    }
};