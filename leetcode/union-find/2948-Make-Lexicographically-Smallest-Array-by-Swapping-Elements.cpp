class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        int n=nums.size();
        //now form vector of groups where each number inside the grp follows the ops that is asked
        vector<vector<int>>grps;
        unordered_map<int,int>grpID;
        //create groups
        int id=-1;
        for(int i=0;i<n;i++)
        {
            if(i==0 || temp[i]-temp[i-1]>limit)
            {
                grps.push_back({});
                id++;
            }
            grps[id].push_back(temp[i]);
            grpID[temp[i]]=id;
        }
        //keep track of how many elements we have take from each grp
        int sz=grps.size();
        vector<int>idx(sz,0);//this will act as a pointer for each group
        for(int i=0;i<n;i++)
        {
            int id=grpID[nums[i]];
            nums[i]=grps[id][idx[id]];
            idx[id]++;
        }
        return nums;
    }
};