class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>temp=nums;
        for(int n:nums)
        temp.push_back(n);
        return temp;
    }
};