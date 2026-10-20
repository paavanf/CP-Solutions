class Solution {
public:
    int resilientSubarray(vector<int>& arr, int k) {
        int n = arr.size();

        int result = 1, l = 0;
        int stepCounter = 0;
        for (int r = 0; r < n; r++) {
            int remainder = arr[r] % k;
            if ((r == 0 )|| (remainder != arr[r - 1] % k)) {
                l = r;
                stepCounter = (k / gcd(remainder, k));
            }

            // if that's not, then maximize
            int sz = r - l + 1;
            if ((sz - 1) % stepCounter == 0) {
                result = max(result, sz);
            }
        }

        return result;
    }
};

/*\

    (len - 1) * (curr el )  % k

    all subrays -> n sq 

    When is a subarray valid?
    1. if for every position, deleting it leaves sum % k == 0

    length of longest such array

    for all elements if we are having the % remainder condition
    then all elements in the subarray must have a rem = arr[i] % k being equal to every other element

    so usingit, we coudl take it step wise as in move the elem as step of k which was initial / gcd(k, remainder)

    
*/
