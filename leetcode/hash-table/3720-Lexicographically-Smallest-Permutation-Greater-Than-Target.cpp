class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int>ct(26,0);
        for(char c:s)
        ct[c-'a']++;
        //now match the target character by character from left to right
        int match=0;
        while(match<n && ct[target[match]-'a']>0)
        {
            ct[target[match]-'a']--;
            match++;
        }
        if(match==n)
        {
            match--;
            ct[target[match]-'a']++;
        }
        for(int i=match;i>=0;i--)
        {
            for(char c=target[i]+1;c<='z';c++)
            {
                if(ct[c-'a']>0)
                {
                    ct[c-'a']--;
                    string ans=target.substr(0,i)+c;
                    for(char ch='a';ch<='z';ch++)
                    {
                        ans.append(ct[ch-'a'],ch);
                    }
                    return ans;
                }
            }
            if(i>0)
            ct[target[i-1]-'a']++;
        }
        return "";
    }
};