class Solution {
  public:
     void f(int idx,vector<int>&arr,int sum,vector<int>&ans)
     {
         int n=arr.size();
         if(idx>=n)
         {
             ans.push_back(sum);
             return;
         }
         //take
         f(idx+1,arr,sum+arr[idx],ans);
         //not take
         f(idx+1,arr,sum,ans);
     }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>ans;
        f(0,arr,0,ans);
        return ans;
    }
};