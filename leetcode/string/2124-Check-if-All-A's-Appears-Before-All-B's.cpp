class Solution {
public:
    bool checkString(string s) {
        int c=0,flag=0;
        for(int i=0;i<s[i] != '\0';i++)
        {
            if(s[i]=='a')
            c++;
            else
            break;
        }
        for(int j=c;j<s[j] != '\0';j++)
        {
            if(s[j]=='a')
            {
            flag=-1;
            break;
            }
        }
        if(flag==-1)
        return false;
        return true;
        
    }
};