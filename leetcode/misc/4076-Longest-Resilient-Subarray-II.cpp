class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
         int n = nums.size();
        int len = 1;
        int maxLen = 1;
        int sum = nums[0];
        for(int i = 1 ; i < n ; i++){
            if(nums[i]%k == nums[i-1]%k){
                len++;
                sum = (sum + nums[i] % k ) % k;
            }
            else{
                len = 1;
                sum = nums[i];
            }
            if(sum == (nums[i] % k))
                maxLen = max(maxLen,len);
        }
        return maxLen;
    }
};