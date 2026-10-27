class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1])ans++;
        }
        return ans;
    }
};