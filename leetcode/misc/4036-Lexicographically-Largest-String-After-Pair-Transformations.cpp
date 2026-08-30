class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;
        for(int x:nums)
        {
            string s="";
            char c='a';
            while(x>=1)
            {
                if(x%2!=0)
                {
                    s+=c;
                    x-=1;
                }
                x/=2;
                c++;
                if(c>='z')
                break;
            }
            //remaing x values
            while(x--)
            s+='z';
            reverse(s.begin(),s.end());
            ans.push_back(s);
        }
        return ans;
    }
};