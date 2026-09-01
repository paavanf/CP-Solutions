/*For the answer to be just greater than target:
1)Match target as long as possible.
2)If possible, replace the current character with the smallest larger available character.
3)Otherwise, go backward and try replacing a previous matched character.
4)Put all remaining characters in sorted order.
*/
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int>fq(26,0);
        for(char c:s)
        fq[c-'a']++;
        //first we will try to match the target
        int i=0;
        while(i<n && fq[target[i]-'a']>0)
        {
            fq[target[i]-'a']--;
            i++;
        }
        //now posi [0..i-1] match the target
        //we make i+1th posi's character just +1
        //if it is not possible we will backtrack
        for(int j=i;j>=0;j--)
        {
            if(j<i)
            fq[target[j]-'a']++;
            //find smallest character greater than target[j]
            if(j<n)
            {
                for(int ch=target[j]-'a'+1;ch<26;ch++)
                {
                    if(fq[ch]>0)
                    {
                        string ans=target.substr(0,j);
                        ans+=char('a'+ch);
                        fq[ch]--;
                        //add remaining characters in sorted order
                        for(int k=0;k<26;k++)
                        ans+=string(fq[k],'a'+k);
                        return ans;
                    }
                }
            }
        }
        return "";
    }
};