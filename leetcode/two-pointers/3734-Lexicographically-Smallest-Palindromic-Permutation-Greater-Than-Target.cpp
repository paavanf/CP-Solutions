/*So we can:
Check whether a palindromic permutation is possible.
Construct the lexicographically smallest palindromic permutation.
If it is already greater than target, return it.
Otherwise, find the next larger permutation of the left half.*/
class Solution {
public:
    //keep trying the left half + middle
    string p(string lh,char mc,int n)
    {
        string ans=lh;
        if(n%2==1)
        ans+=mc;
        string rh=lh;
        reverse(rh.begin(),rh.end());
        ans+=rh;
        return ans;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();
        vector<int>fq(26,0);
        for(char c:s)
        fq[c-'a']++;
        //check if palindromic permutation is possible
        int oddFq=0;
        char mc;
        for(int i=0;i<26;i++)
        {
            if(fq[i]%2==1)
            {
                oddFq++;
                mc=char('a'+i);
            }
        }
        if(oddFq>(n%2))
        return "";
        //now create the left half
        vector<int>lh_fq(26,0);
        for(int i=0;i<26;i++)
        lh_fq[i]=fq[i]/2;
        string lh_target=target.substr(0,n/2);
        //first we will try to match the target
        int i=0;
        while(i<n/2 && lh_fq[lh_target[i]-'a']>0)
        {
            lh_fq[lh_target[i]-'a']--;
            i++;
        }
        //if exact match on first half makes the palindrome greater than the target then return it
        if(i==n/2)
        {
           string same_lh=p(lh_target,mc,n);
           if(same_lh>target)
           return same_lh;
        }
        /*
        Same greedy logic as LC 3720.

        Find the rightmost position where we can
        place the smallest character greater than targetLeft[j].
        */
        for(int j=min(i,n/2-1);j>=0;j--)
        {
            if(j<i)
            lh_fq[lh_target[j]-'a']++;
            for(int ch=lh_target[j]-'a'+1;ch<26;ch++)
            {
                if(lh_fq[ch]>0)
                {
                    string lh=lh_target.substr(0,j);
                    lh+=char('a'+ch);
                    lh_fq[ch]--;
                    for(int k=0;k<26;k++)
                    lh+=string(lh_fq[k],char('a'+k));
                    return p(lh,mc,n);
                }
            }
        }
        return "";
    }
};