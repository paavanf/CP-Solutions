class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        return false;
        int fq[26]={0};
        for(char c:s)
        fq[c-'a']++;
        for(char c:t)
        fq[c-'a']--;
        for(int i=0;i<26;i++)
        {
            if(fq[i]!=0)
            return false;
        }
        return true;
    }
};