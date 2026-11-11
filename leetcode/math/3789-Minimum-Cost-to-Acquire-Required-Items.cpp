class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
         if (need1 == 0 && need2 == 0) return 0;

        long long total = 0;

        // Step 1: Use type-3 items for overlap if beneficial
        if (costBoth < 1LL * cost1 + cost2) {
            int common = min(need1, need2);
            total += 1LL * common * costBoth;
            need1 -= common;
            need2 -= common;
        }

        // Step 2: Fill remaining needs using the cheapest option
        total += 1LL * need1 * min(cost1, costBoth);
        total += 1LL * need2 * min(cost2, costBoth);

        return total;
    }
};