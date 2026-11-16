class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k)
        {
            string ns="";
            for(int i=0;i<s.length();i+=k)
            {
                int sm=0;
                for(int j=i;j<i+k && j<s.length();j++)
                {
                    sm+=s[j]-'0';
                }
                ns+=to_string(sm);
            }
            s=ns;
        }
        return s;
    }
};