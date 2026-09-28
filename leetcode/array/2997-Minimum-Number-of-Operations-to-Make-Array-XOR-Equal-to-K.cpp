class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int tot=0;
        for(int n:nums)
        {
            tot^=n;
        }
        int ct=0;
        while(k||tot)
        {
            if((k%2)!=(tot%2))
            ct++;
            k/=2;
            tot/=2;
        }
        return ct;
    }
};