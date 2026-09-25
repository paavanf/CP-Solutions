class Solution {
public:
    set<string>f(const string &s)
    {
        set<string>s1,s2={""};
        int n=s.size();
        int i=0;
        while(i<n)
        {
            if(s[i]=='{')
            {
                int j=i,braceCt=0;
                while(j<n)
                {
                    if(s[j]=='{')
                    braceCt++;
                    else if (s[j]=='}')
                    braceCt--;
                    if(braceCt==0)
                    break;
                    j++;
                }
                //form the string along with concat
                set<string>s3=f(s.substr(i+1,j-i-1)),s4;
                for(const string &a:s2)
                {
                    for(const string &b:s3)
                    {
                        s4.insert(a+b);
                    }
                }
                s2=s4;
                i=j+1;
            }
            else if(s[i]==',')
            {
                s1.insert(s2.begin(),s2.end());
                s2={""};
                i++;
            }
            else
            {
                set<string>s5;
                for(const string &c:s2)
                {
                    s5.insert(c+s[i]);
                }
                s2=s5;
                i++;
            }
        }
        s1.insert(s2.begin(),s2.end());
        return s1;
    }
    vector<string> braceExpansionII(string s) {
        set<string>ans=f(s);
        return vector<string>(ans.begin(),ans.end());
    }
};