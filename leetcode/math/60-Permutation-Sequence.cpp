class Solution {
public:
    int f(int n)
    {
        int p=1;
        for(int i=1;i<=n;i++)
        p*=i;
        return p;
    }
    string getPermutation(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++)
        nums.push_back(i);
        // Number of permutations for each first digit
        int fact=f(n-1);
        // Convert k to 0-based
        k--;
        string ans="";
        while(!nums.empty())
        {
            //find the block of k
            int idx=k/fact;
            //add number to answer
            ans+=to_string(nums[idx]);
            //remove number from nums
            nums.erase(nums.begin()+idx);
            //check for empty
            if(nums.empty())
            break;
            //update k
            k%=fact;
            // Calculate factorial for remaining numbers
            fact/=nums.size();
        }
        return ans;
    }
};