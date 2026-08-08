class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(5, 0);
        vector<int> curr(5, 0);

        for(int ind = n-1; ind >= 0; ind--) {
            for(int trans = 1; trans < 5; trans++) {

                if(trans % 2 == 0) {
                    int take = next[trans - 1] - prices[ind];
                    int notTake = next[trans];

                    curr[trans] = max(take, notTake);
                }
                else {
                    int sell = next[trans - 1] + prices[ind];
                    int notSell = next[trans];

                    curr[trans] = max(sell, notSell);
                }

            }
            next = curr;
        }
        return next[4];
    }
};