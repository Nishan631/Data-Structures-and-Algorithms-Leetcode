class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> next(2, 0);
        vector<int> curr(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {

            int take = next[0] - prices[ind];
            int notTake = next[1];

            curr[1] = max(take, notTake);

            int sell = next[1] + prices[ind] - fee;
            int notSell = next[0];

            curr[0] = max(sell, notSell);

            next = curr;
        }
        return next[1];
    }
};