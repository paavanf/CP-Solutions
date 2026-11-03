class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int moves=0;
        int val=*max_element(nums.begin(),nums.end());
        for(int a: nums)
            {
                moves+=val-a;
            }
        return moves;
    }
};