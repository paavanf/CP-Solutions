class Solution {
public:
    void f(int idx,int amt,vector<int>&arr,vector<vector<int>>&ans,vector<int>temp)
    {
        //base case
        int n=arr.size();
        if(amt==0){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            if(i>idx && arr[i-1]==arr[i])
            continue;
            if(arr[i]<=amt)
            {
                temp.push_back(arr[i]);
                f(i+1,amt-arr[i],arr,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int amt) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(arr.begin(),arr.end());//to remove duplicates
        f(0,amt,arr,ans,temp);
        return ans;
    }
};