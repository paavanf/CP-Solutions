class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int> a(26,n),b(26,-1);
        for(int i=0;i<n;i++)
        {
            a[s[i]-'a']=min(a[s[i]-'a'],i);
            b[s[i]-'a']=i;
        }
        vector<pair<int,int>> arr;
        for(int i=0;i<26;i++)
        {
            if(b[i]==-1) 
                continue;
            bool b1=true;
            for(int j=a[i];j<=b[i];j++)
            {
                if(a[s[j]-'a']<a[i])
                {
                    b1=false;
                    break;
                }
                b[i]=max(b[i],b[s[j]-'a']);
            }
            if(b1) 
                arr.push_back({b[i],a[i]});
        }
        sort(arr.begin(),arr.end());
        vector<string> ans;
        int i=-1;
        for(auto j:arr)
            if(j.second>i)
            {
                ans.push_back(s.substr(j.second,j.first-j.second+1));
                i=j.first;
            }
        return ans; 
    }
};