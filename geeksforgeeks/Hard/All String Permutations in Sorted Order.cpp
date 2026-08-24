class Solution {
  public:
     void f(int idx,string&s,vector<string>&ans)
     {
         //int n1=temp.size();
         int n=s.size();
         if(idx>=n)
         {
             ans.push_back(s);
             return;
         }
         for(int i=idx;i<n;i++)
         {
             swap(s[idx],s[i]);
             f(idx+1,s,ans);
             swap(s[idx],s[i]);
         }
     }
    vector<string> permutation(string s) {
        // code here
        //vector<bool>used(s.size(),false);
       
        vector<string>ans;
        //string temp;
        f(0,s,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};