class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> next((2 * k) + 1, 0);
        vector<int> curr((2 * k) + 1, 0);
        
        for(int ind = n-1; ind >= 0; ind--) {
            for(int trans = 1; trans <= (2 * k); trans++) {

                if(trans % 2 == 0) {
                    int buy = next[trans - 1] - prices[ind];
                    int notBuy = next[trans];

                    curr[trans] = max(buy, notBuy);
                }
                else {
                    int sell = next[trans - 1] + prices[ind];
                    int notSell = next[trans];

                    curr[trans] = max(sell, notSell);
                }
            }
            next = curr;
        }
        return curr[2 * k];
    }
};