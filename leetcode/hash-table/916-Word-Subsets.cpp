class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>req(26,0);
        for(string w:words2)
        {
            vector<int>fq(26,0);
            for(char c:w)
            {
                fq[c-'a']++;
            }
                for(int i=0;i<26;i++)
            {
                req[i]=max(req[i],fq[i]);//for example ('e','eo')
            }
        }
        vector<string>ans;
        for(string w:words1)
        {
            vector<int>fq(26,0);
            for(char c:w)
            {
                fq[c-'a']++;
            }
                bool flag=true;
                for(int i=0;i<26;i++)
                {
                    if(fq[i]<req[i])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                ans.push_back(w);
        }
        return ans;
    }
};