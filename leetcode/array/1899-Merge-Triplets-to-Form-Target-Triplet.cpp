class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        bool idx1=false,idx2=false,idx3=false;
        for(int i=0;i<n;i++)
        {
            //base case
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2])
            continue;
            if(triplets[i][0]==target[0])
            idx1=true;
            if(triplets[i][1]==target[1])
            idx2=true;
            if(triplets[i][2]==target[2])
            idx3=true;
        }
        if(idx1 && idx2 && idx3)
        return true;
        return false;
    }
};