class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1)
            return 0;

        vector<vector<int>> dp(n+2, vector<int>(2, 0));           // Base case already covered.

        for(int ind = n-1; ind >= 0; ind--) {
            for(int buy = 0; buy <= 1; buy++) {

                if (buy) {
                    int take = dp[ind + 1][0] - prices[ind];
                    int notTake = dp[ind + 1][1];

                    dp[ind][buy] = max(take, notTake);
                }
                else {
                    int sell = dp[ind + 2][1] + prices[ind];
                    int notSell = dp[ind + 1][0];

                    dp[ind][buy] = max(sell, notSell);
                }
            }
        }
        return dp[0][1];
    }
};