class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>last(26,0);
        for(int i=0;i<n;i++)//get the last occurence
        last[s[i]-'a']=i;
        vector<int>pLen;
        int sp=0,ep=0;
        for(int i=0;i<n;i++)
        {
            ep=max(ep,last[s[i]-'a']);
            if(i==ep)
            {
                pLen.push_back(ep-sp+1);
                sp=ep+1;
            }
        }
        return pLen;
    }
};