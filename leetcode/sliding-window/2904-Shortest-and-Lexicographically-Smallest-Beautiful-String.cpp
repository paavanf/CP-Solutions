class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int l=0,ct=0,len=0;
        string ans="";
        for(int r=0;r<n;r++)
        {
            if(s[r]=='1')
            ct++;
            while(ct>k)
            {
                if(s[l]=='1')
                ct--;
                l++;
            }
            //for leading zeroes
            if(ct==k)
            {
                while(s[l]=='0')
                l++;
                len=r-l+1;
                string curr=s.substr(l,len);
                //3 cases to check for replacement
                if(ans=="" || curr.size()<ans.size() || (curr.size()==ans.size() && curr<ans))
                ans=curr;
            }
        }
        return ans;
    }
};